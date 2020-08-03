/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:18:30 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 22:18:30 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zerostr(size_t i)
{
	char	*str;

	str = ft_strnew(i);
	while (i)
	{
		i--;
		str[i] = '0';
	}
	return (str);
}

char	*ftostr(long double f, t_pfdata *pfdata)
{
	char	*str;
	char	*new;

	str = llitoa(f, pfdata);
	new = ft_strjoin(str, ".");
	free(str);
	return (new);
}

char	*fstradd(char *str1, char *str2)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (res);
}

char	*ftoa(long double f, t_pfdata *pfdata)
{
	char		*str1;
	char		*str2;
	int			i;
	long double	k;
	int			dotprec;

	dotprec = pfdata->dotprec ? pfdata->dotprec : 6;
	pfdata->dotprec = 0;
	str1 = ftostr(f, pfdata);
	f = f < 0 ? -f : f;
	while (f > 1 && f > 0)
		f = f - (long int)f;
	i = 0;
	while (i < 18 && i < dotprec)
	{
		f = f * 10;
		i++;
	}
	k = f - (long int)f;
	if ((long int)(k * 10) > 4)
		f = f + 1;
	str2 = llitoa(f, pfdata);
	if (i < dotprec)
		str2 = fstradd(str2, zerostr(dotprec - i));
	return (fstradd(str1, str2));
}
