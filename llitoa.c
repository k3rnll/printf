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

char 		*convert_d(char *str, t_pfdata *pfdata)
{
	char 	*tmp;
	char 	*res;
	size_t 	len;
	int 	i;

	i = 0;
	len = *str == '-' ? ft_strlen(str) - 1 : ft_strlen(str);
	if (pfdata->dotprec > 0 && pfdata->dotprec > len)
	{
//		len = str[0] == '-' ? len - 1 : len;
		tmp = ft_strnew(pfdata->dotprec - len);
		if (pfdata->plus || pfdata->space){
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
	if (pfdata->zero && !pfdata->dotprec && !pfdata->align && pfdata->prec > len)
	{
		len = *str == '-' ? len + 1 : len;
		tmp = ft_strnew(pfdata->prec - len);
		if (pfdata->plus || pfdata->space)
			tmp[i++] = pfdata->plus ? '+' : ' ';
//		if (*str == '-')
//			tmp[i++] = '-';
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
	if ((pfdata->plus || pfdata->space) && *str != '-') {
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
	char 		*tstr;

	tmp = n;
	len = ft_numlen(n);
	if (n < 0)
	{
//		tmp = (unsigned long long) tmp;
		len++;
	}
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
	if (tmp < 0)
		str[len - 1] = (char)(-1 * (tmp % 10) + '0');
	else
		str[len - 1] = (char)((tmp % 10) + '0');
	if (n < 0)
		str[0] = '-';
	return (convert_d(str, pfdata));
}