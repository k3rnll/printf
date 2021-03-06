/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouise <clouise@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:51:25 by clouise           #+#    #+#             */
/*   Updated: 2020/08/03 22:51:48 by clouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		domod(t_pfdata *pfdata)
{
	if (pfdata->format[pfdata->i - 1] == 'h')
	{
		if (pfdata->format[pfdata->i - 2] == 'h')
			pfdata->x = (char)va_arg(pfdata->args, int);
		else
			pfdata->x = (short)va_arg(pfdata->args, int);
	}
	else if (pfdata->format[pfdata->i - 1] == 'l')
	{
		if (pfdata->format[pfdata->i - 2] == 'l')
			pfdata->x = (long long)va_arg(pfdata->args, long long int);
		else
			pfdata->x = (long int)va_arg(pfdata->args, long int);
	}
	else
		pfdata->x = va_arg(pfdata->args, int);
}
