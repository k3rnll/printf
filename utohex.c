/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:55:46 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 18:40:39 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_z(char *str, int len, t_pfdata *pfdata)
{
	int			i;

	i = 0;
	while (i < pfdata->dotprec - len)
		str[i++] = '0';
}

char	*conv_hex(char *str, char c, t_pfdata *pfdata)
{
	char		*tstr;
	char		*res;
	int			len;

	len = ft_strlen(str);
	res = str;
	if (pfdata->dotprec > len)
	{
		pfdata->dotprec = pfdata->alt ? pfdata->dotprec + 2 : pfdata->dotprec;
		tstr = ft_strnew(pfdata->dotprec - len);
		fill_z(tstr, len, pfdata);
		res = ft_strjoin(tstr, str);
		res[1] = pfdata->alt ? c : res[1];
		free(str);
		free(tstr);
	}
	else if (pfdata->alt == '#' && str[0] != '0' && str[0])
	{
		res = ft_strjoin("0x", str);
		res[1] = c;
		free(str);
	}
	return (res);
}

int		move_hex(unsigned long long *n, long long *p, t_pfdata *pfdata)
{
	int		i;

	i = 0;
	if (*p > -2147483649 && *p < 2147483648)
	{
		*n = pfdata->mod[0] == 'h' ? *n << 48 : *n;
		*n = !pfdata->mod[0] ? *n << 32 : *n;
		i = pfdata->mod[0] == 'h' ? 12 : 8;
		i = pfdata->mod[0] == 'l' ? 0 : i;
		*n = pfdata->mod[1] == 'h' ? *n << 8 : *n;
		i = pfdata->mod[1] == 'h' ? 14 : i;
	}
	while (!(*n & 0xF000000000000000) && i < 15)
	{
		*n = *n << 4;
		i++;
	}
	return (i);
}

char	*utohex(unsigned long long n, char c, t_pfdata *pfdata)
{
	char			*str;
	long long		p;
	unsigned int	tmp;
	int				i;
	int				k;

	k = 0;
	str = ft_strnew(18);
	p = (signed long long)n;
	i = move_hex(&n, &p, pfdata);
	while (i < 16)
	{
		tmp = n >> 60;
		if (tmp < 10)
			str[k] = (char)(tmp + 48);
		else
			str[k] = (char)(tmp + c - 33);
		n = n << 4;
		k++;
		i++;
	}
	if (pfdata->dot && !pfdata->dotprec && p == 0)
		str[0] = 0;
	return (conv_hex(str, c, pfdata));
}
