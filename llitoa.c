/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:18:54 by k3                #+#    #+#             */
/*   Updated: 2020/08/03 20:46:15 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long long int n)
{
	int		len;

	len = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char		*conv_v1(char *str, int len, t_pfdata *pfdata)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	tmp = ft_strnew(pfdata->dotprec - len);
	if (pfdata->plus || pfdata->space)
	{
		tmp[i++] = pfdata->plus ? '+' : ' ';
		len--;
	}
	while (i < pfdata->dotprec - len)
		tmp[i++] = '0';
	res = ft_strjoin(tmp, str);
	if (res[i] == '-')
	{
		res[0] = '-';
		res[i] = '0';
	}
	free(str);
	free(tmp);
	return (res);
}

char		*conv_v2(char *str, int len, t_pfdata *pfdata)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	len = *str == '-' ? len + 1 : len;
	tmp = ft_strnew(pfdata->prec - len);
	if (pfdata->plus || pfdata->space)
		tmp[i++] = pfdata->plus ? '+' : ' ';
	while (i < pfdata->prec - len)
		tmp[i++] = '0';
	res = ft_strjoin(tmp, str);
	if (res[i] == '-' && pfdata->prec - len)
	{
		res[0] = '-';
		res[i] = '0';
	}
	free(str);
	free(tmp);
	return (res);
}

char		*convert_d(char *str, t_pfdata *pfdata)
{
	char	*res;
	int		len;

	len = *str == '-' ? ft_strlen(str) - 1 : ft_strlen(str);
	if (pfdata->dotprec > 0 && pfdata->dotprec > len)
		return (conv_v1(str, len, pfdata));
	if (pfdata->zero && !pfdata->dotprec && !pfdata->align \
		&& pfdata->prec > len)
		return (conv_v2(str, len, pfdata));
	if ((pfdata->plus || pfdata->space) && *str != '-')
	{
		res = pfdata->plus ? ft_strjoin("+", str) : ft_strjoin(" ", str);
		free(str);
		return (res);
	}
	return (str);
}

char		*llitoa(long long int n, t_pfdata *pfdata)
{
	long long	tmp;
	int			len;
	char		*str;

	tmp = n;
	len = ft_numlen(n);
	len = n < 0 ? len + 1 : len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (pfdata->dot && !pfdata->dotprec && !n)
		return (str);
	while (tmp / 10 != 0)
	{
		if (tmp < 0)
			str[len - 1] = (char)(-1 * (tmp % 10) + '0');
		else
			str[len - 1] = (char)((tmp % 10) + '0');
		tmp = tmp / 10;
		len--;
	}
	str[len - 1] = tmp < 0 ? (-1 * (tmp % 10) + '0') : ((tmp % 10) + '0');
	str[0] = n < 0 ? '-' : str[0];
	return (convert_d(str, pfdata));
}
