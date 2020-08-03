/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:50:43 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 21:11:03 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_digit(char *str, t_pfdata *pfdata)
{
	if (pfdata->align == '-')
	{
		ft_putstr(str);
		fill_space(pfdata, ' ');
	}
	else
	{
		pfdata->alt && pfdata->zero ? ft_putnstr(str, 2) : 0;
		fill_space(pfdata, pfdata->zero && pfdata->dotprec < 1 ? '0' : ' ');
		if (str[0] == '-' && pfdata->zero)
			ft_putstr(&str[0]);
		else if (pfdata->alt && pfdata->zero)
			ft_putstr(&str[2]);
		else
			ft_putstr(str);
	}
}

void	disp_str(char *str, t_pfdata *pfdata)
{
	int		len;

	len = ft_strlen(str);
	pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
	disp_digit(str, pfdata);
	pfdata->i++;
	pfdata->len += len;
	free(str);
}

void	digits(t_pfdata *pfdata)
{
	char	*str;
	char	c;

	str = NULL;
	c = pfdata->format[pfdata->i];
	if (ft_strchr("diouxX", c))
		domod(pfdata);
	if (c == 'f' && pfdata->format[pfdata->i - 1] != 'L')
		str = ftoa(va_arg(pfdata->args, double), pfdata);
	if (c == 'f' && pfdata->format[pfdata->i - 1] == 'L')
		str = ftoa(va_arg(pfdata->args, long double), pfdata);
	if (c == 'd' || c == 'i')
		str = llitoa(pfdata->x, pfdata);
	if (c == 'o')
		str = otoa(pfdata->x, pfdata);
	if (c == 'u')
		str = ft_utoa(pfdata->x, pfdata);
	if (c == 'x' || c == 'X')
		str = utohex(pfdata->x, c, pfdata);
	if (str)
		disp_str(str, pfdata);
}
