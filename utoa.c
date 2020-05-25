#include "ft_printf.h"

static int	ft_ulen(unsigned long long u)
{
	int		len;

	len = 0;
	while (u / 10 != 0)
	{
		u = u / 10;
		len++;
	}
	len++;
	return (len);
}

char 		*convert_u(char *str, t_pfdata *pfdata)
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
		while (i < pfdata->dotprec - len)
			tmp[i++] = '0';
		res = ft_strjoin(tmp, str);
		free(str);
		free(tmp);
		return (res);
	}
	return (str);
}

char		*ft_utoa(unsigned long long u, t_pfdata *pfdata)
{
	int			len;
	char		*str;
	signed long long	p;

	p = (signed long long)u;

	if (pfdata->mod[0] != 'l' && (u < 0 || u > 0xFFFFFFFF))
		u = u - 0xFFFFFFFF00000000;

	len = ft_ulen(u);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (u / 10 != 0)
	{
		str[len - 1] = ((u % 10) + '0');
		u = u / 10;
		len--;
	}
	str[len - 1] = ((u % 10) + '0');
	return (convert_u(str, pfdata));
}
