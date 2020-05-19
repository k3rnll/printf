#include "ft_printf.h"

char 	*utohex(unsigned long long n, char c, int len)
{
	char			*str;
	long long		p;
	unsigned int	tmp;
	int				i;
	int 			k;

	i = 0;
	k = 0;
//	tmp = n;
	str = ft_strnew(16);
//	str[0] = '0';
//	str[1] = 'x';
	p = (signed long long)n;
	if (p > -2147483649 && p < 2147483648)
	{
//		n = (unsigned long long)p;
		n = n << 32;
		i = 8;
	}
	while (!(n & 0xF000000000000000) && i < 15)
	{
		n = n << 4;
		i++;
	}
	while (i < 16)
	{
//		tmp = n & 0xF0000000;
		tmp = n >> 60;
		if (tmp < 10)
			str[k] = (char)(tmp + 48);
		else
			str[k] = (char)(tmp + c - 33);
		n = n << 4;
		k++;
		i++;
	}
	return(str);
}