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

char 	*otoa(unsigned int n)
{
	int			len;
	char		*str;

	len = ft_olen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (n / 8 != 0)
	{
		str[len - 1] = ((n % 8) + '0');
		n = n / 8;
		len--;
	}
	str[len - 1] = ((n % 8) + '0');
	return(str);
}