#include "ft_printf.h"

static int	ft_ulen(unsigned int u)
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

char		*ft_utoa(unsigned int u)
{
	int			len;
	char		*str;

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
