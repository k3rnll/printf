/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:52:15 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 20:11:16 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_pfdata *pfdata, char c)
{
	while (pfdata->prec > 0)
	{
		ft_putchar(c);
		pfdata->len++;
		pfdata->prec--;
	}
}

void	p_char(t_pfdata *pfdata)
{
	const char	*str;
	char		t;
	char		c;

	str = &(pfdata->format[pfdata->i]);
	t = pfdata->zero && !pfdata->align ? '0' : ' ';
	c = *str == 'c' ? va_arg(pfdata->args, int) : '%';
	pfdata->prec = (pfdata->prec > 1) ? (pfdata->prec - 1) : 0;
	pfdata->align == '-' ? ft_putchar(c) : fill_space(pfdata, t);
	pfdata->align == '-' ? fill_space(pfdata, t) : ft_putchar(c);
	if (c == '%' && *(str + 1) && ft_strchr("scpdiouxXf", *(str + 1)))
	{
		pfdata->i++;
		pfdata->len++;
		ft_putchar(pfdata->format[pfdata->i]);
	}
	pfdata->i++;
	pfdata->len++;
}

void	p_string(t_pfdata *pfdata)
{
	char	*str;
	int		len;

	if (!(str = va_arg(pfdata->args, char*)))
		str = "(null)";
	len = ft_strlen(str);
	pfdata->prec = pfdata->prec < 0 ? -pfdata->prec : pfdata->prec;
	if (pfdata->dot && pfdata->dotprec < len && pfdata->dotprec >= 0)
		len = pfdata->dotprec;
	pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
	pfdata->align == '-' ? ft_putnstr(str, len) : fill_space(pfdata, ' ');
	pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putnstr(str, len);
	pfdata->i++;
	pfdata->len += len;
}

void	p_pointer(t_pfdata *pfdata)
{
	char	*str;
	int		len;

	str = ft_ptoa(va_arg(pfdata->args, int*), pfdata);
	len = ft_strlen(str);
	len = (pfdata->dot && pfdata->dotprec == 0) ? 2 : len;
	pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
	pfdata->align == '-' ? ft_putnstr(str, len) : fill_space(pfdata, ' ');
	pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putnstr(str, len);
	pfdata->i++;
	pfdata->len += len;
	free(str);
}

void	reparse(t_pfdata *pfdata)
{
	if (pfdata->format[pfdata->i] == 'c' || pfdata->format[pfdata->i] == '%')
		p_char(pfdata);
	else if (pfdata->format[pfdata->i] == 's')
		p_string(pfdata);
	else if (pfdata->format[pfdata->i] == 'p')
		p_pointer(pfdata);
}
