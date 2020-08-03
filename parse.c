/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouise <clouise@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:29:38 by clouise           #+#    #+#             */
/*   Updated: 2020/08/03 22:30:11 by clouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse(t_pfdata *pfdata)
{
	while (pfdata->format[pfdata->i] != '\0')
	{
		if (pfdata->format[pfdata->i] == '%')
		{
			pfdata->i++;
			if (!pfdata->format[pfdata->i])
				break ;
			reinit(pfdata);
			chk_flag(pfdata);
			chk_mod(pfdata);
			chk_conv(pfdata);
			continue;
		}
		if (pfdata->format[pfdata->i] == '\0')
			break ;
		ft_putchar(pfdata->format[pfdata->i++]);
		pfdata->len++;
	}
}
