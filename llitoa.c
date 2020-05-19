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

char		*llitoa(long long int n)
{
	long long	tmp;
	int			len;
	char		*str;

	tmp = n;
	len = ft_numlen(n);
	if (n < 0)
	{
//		tmp = (unsigned long long) tmp;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
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
	return (str);
}