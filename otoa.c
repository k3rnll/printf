#include "ft_printf.h"

static int	ft_olen(unsigned int u)
{
	int		len;

	len = 0;
	while (u / 8 != 0)
	{
		u = u / 8;
		len++;
	}
	len++;
	return (len);
}

char 		*convert_o(char *str, t_pfdata *pfdata)
{
	char 	*tmp;
	char 	*res;
	int 	len;
	int 	i;

	i = 0;
	len = ft_strlen(str);
	if (pfdata->dotprec > len)
	{
		tmp = ft_strnew(pfdata->dotprec - len);
//		if (pfdata->plus) {
//			tmp[i++] = '+';
//			len--;
//		}
		while (i < pfdata->dotprec - len)
			tmp[i++] = '0';
		res = ft_strjoin(tmp, str);
//		if (res[i] == '-')
//		{
//			res[0] = '-';
//			res[i] = '0';
//		}
		free(str);
		free(tmp);
		return (res);
	}
	if (pfdata->dot && !pfdata->alt) {
		pfdata->zero = 0;
		str[0] = 0;
	}
	return (str);
}

char 	*otoa(unsigned int n, t_pfdata *pfdata)
{
	int			len;
	char		*str;

	len = ft_olen(n);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (n / 8 != 0)
	{
		str[len - 1] = ((n % 8) + '0');
		n = n / 8;
		len--;
	}
	str[len - 1] = ((n % 8) + '0');
	if (pfdata->alt && str[0] != '0')
		str = ft_strjoin("0", str);
	return(convert_o(str, pfdata));
}