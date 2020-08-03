/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:40:15 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 22:42:44 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_flag(t_pfdata *pfdata)
{
	const char	*str;

	str = pfdata->format;
	while (ft_strchr(pfdata->flags, str[pfdata->i]))
	{
		pfdata->alt = (str[pfdata->i] == '#') ? '#' : pfdata->alt;
		pfdata->align = (str[pfdata->i] == '-') ? '-' : pfdata->align;
		pfdata->zero = (str[pfdata->i] == '0') ? 1 : pfdata->zero;
		pfdata->space = (str[pfdata->i] == ' ') ? ' ' : pfdata->space;
		pfdata->plus = (str[pfdata->i] == '+') ? '+' : pfdata->plus;
		pfdata->dot = (str[pfdata->i] == '.') ? '.' : pfdata->dot;
		pfdata->i++;
	}
}
