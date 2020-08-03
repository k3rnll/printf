/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:47:17 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 22:47:37 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_mod(t_pfdata *pfdata)
{
	if (ft_strchr("hl", pfdata->format[pfdata->i]))
	{
		pfdata->mod[0] = pfdata->format[pfdata->i];
		pfdata->i++;
		if (pfdata->format[pfdata->i] == pfdata->mod[0])
		{
			pfdata->mod[1] = pfdata->mod[0];
			pfdata->i++;
		}
	}
}
