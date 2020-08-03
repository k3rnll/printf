/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:20:13 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 21:29:40 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_aster(t_pfdata *pfdata)
{
	size_t		k;
	const char	*str;

	k = pfdata->i - 1;
	str = pfdata->format;
	while ((str[k] == '*' || ft_isdigit(str[k])) && str[k] != '%')
		k--;
	if (str[k] == '.')
	{
		pfdata->dot = '.';
		while ((ft_strchr("*.", str[k]) || ft_isdigit(str[k])) && str[k] != '%')
			k--;
		while (str[++k] != '.')
			pfdata->prec = str[k] == '*' ? va_arg(pfdata->args, int) : 0;
		while (k < pfdata->i)
		{
			pfdata->dotprec = str[k] == '*' ? va_arg(pfdata->args, int) : 0;
			k++;
		}
	}
	else
		while (++k < pfdata->i)
			pfdata->prec = str[k] == '*' ? va_arg(pfdata->args, int) : 0;
}

void	chk_prec(t_pfdata *pfdata)
{
	size_t	k;

	chk_aster(pfdata);
	k = pfdata->i - 1;
	while (ft_isdigit(pfdata->format[k]) && pfdata->format[k] != '%')
		k--;
	if (pfdata->dot)
	{
		if (ft_isdigit(pfdata->format[k + 1]))
			pfdata->dotprec = ft_atoi(&(pfdata->format[k + 1]));
		while (pfdata->format[k] != '.')
			k--;
		k--;
		while (ft_isdigit(pfdata->format[k]) && pfdata->format[k] != '%')
			k--;
		if (ft_isdigit(pfdata->format[k + 1]))
			pfdata->prec = ft_atoi(&(pfdata->format[k + 1]));
		if (!pfdata->zero)
			pfdata->zero = pfdata->prec ? 0 : 1;
	}
	else if (ft_isdigit(pfdata->format[k + 1]))
		pfdata->prec = ft_atoi(&(pfdata->format[k + 1]));
	pfdata->align = pfdata->prec < 0 ? '-' : pfdata->align;
	pfdata->prec = !pfdata->dot && pfdata->prec < 0 \
		? -pfdata->prec : pfdata->prec;
}
