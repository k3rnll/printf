/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:15:44 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 20:17:13 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_p(char *str, t_pfdata *pfdata)
{
	char	*tstr;
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (pfdata->dotprec > 16 - i)
		i = 16 - pfdata->dotprec;
	tstr = i == 16 ? ft_strjoin("0x", "0") : ft_strjoin("0x", &str[i]);
	free(str);
	return (tstr);
}

char	*ft_ptoa(void *ptr, t_pfdata *pfdata)
{
	char			*str;
	int				k;
	unsigned long	i;
	unsigned long	tmp;

	str = ft_strnew(16);
	k = 0;
	i = (unsigned long)ptr;
	while (k < 16)
	{
		tmp = i & 0xF000000000000000;
		tmp = tmp >> 60;
		if (tmp < 10)
			str[k] = (char)(tmp + 48);
		else
			str[k] = (char)(tmp + 87);
		i = i << 4;
		k++;
	}
	return (convert_p(str, pfdata));
}
