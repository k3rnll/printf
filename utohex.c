#include "ft_printf.h"

char 	*utohex(unsigned long long n, char c, t_pfdata *pfdata)
{
	char			*str;
	char 			*tstr;
	long long		p;
	unsigned int	tmp;
	int				i;
	int 			k;

	i = 0;
	k = 0;
	str = ft_strnew(18);
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
	if (pfdata->alt == '#' && str[0] != '0')
	{
		tstr = str;
		str = ft_strjoin("0x", str);
		str[1] = c;
		free(tstr);
	}
	if (pfdata->dot && p == 0)
		str[0] = 0;
	return(str);
}