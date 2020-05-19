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

char		*ft_utoa(unsigned long long u, t_pfdata *pfdata)
{
	int			len;
	char		*str;
	signed long long	p;

	p = (signed long long)u;

	if (pfdata->flag[0] != 'l' && (u < 0 || u > 0xFFFFFFFF))
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
	return (str);
}
