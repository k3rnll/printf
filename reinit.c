/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouise <clouise@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:44:27 by clouise           #+#    #+#             */
/*   Updated: 2020/08/03 22:47:02 by clouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reinit(t_pfdata *pfdata)
{
	pfdata->mod[0] = 0;
	pfdata->mod[1] = 0;
	pfdata->prec = 0;
	pfdata->dotprec = 0;
	pfdata->alt = 0;
	pfdata->align = 0;
	pfdata->zero = 0;
	pfdata->space = 0;
	pfdata->plus = 0;
	pfdata->dot = 0;
}
