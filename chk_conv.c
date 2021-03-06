/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:33:42 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 22:35:29 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chk_conv(t_pfdata *pfdata)
{
	int		k;

	while (pfdata->format[pfdata->i])
	{
		k = 0;
		while (pfdata->conversion[k] != '\0')
		{
			if (pfdata->format[pfdata->i] == pfdata->conversion[k])
			{
				chk_prec(pfdata);
				reparse(pfdata);
				digits(pfdata);
				return (0);
			}
			k++;
		}
		if (pfdata->format[pfdata->i] == '\0')
			break ;
		pfdata->i++;
	}
	return (0);
}
