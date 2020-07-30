#include "ft_printf.h"

char 	*utohex(unsigned long long n, char c, t_pfdata *pfdata)
{
	char			*str;
	char 			*tstr;
	char 			*res;
	long long		p;
	unsigned int	tmp;
	int				i;
	int 			k;
	size_t			len;

	i = 0;
	k = 0;
	str = ft_strnew(18);
	p = (signed long long)n;
	if (p > -2147483649 && p < 2147483648) {
		n = pfdata->mod[0] == 'h' ? n << 48 : n;
		n = !pfdata->mod[0] ? n << 32 : n;
		i = pfdata->mod[0] == 'h' ? 12 : 8;
		i = pfdata->mod[0] == 'l' ? 0 : i;
		n = pfdata->mod[1] == 'h' ? n << 8 : n;
		i = pfdata->mod[1] == 'h' ? 14 : i;




//		if (pfdata->mod[0] == 'h' ) {
//			n = n << 56;
//			i = 14;
//		} else {
//		n = n << 32;
//		i = 8;
//	}
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
	if (pfdata->dot && p == 0)
		str[0] = 0;
	len = ft_strlen(str);
	if (pfdata->dotprec > len)
	{
		i = 0;
		pfdata->dotprec = pfdata->alt ? pfdata->dotprec + 2 : pfdata->dotprec;
		tstr = ft_strnew(pfdata->dotprec - len);
		while (i < pfdata->dotprec - len)
			tstr[i++] = '0';
		res = ft_strjoin(tstr, str);
		res[1] = pfdata->alt ? c : res[1];
		free(str);
		free(tstr);
		return (res);
	}
//		if (pfdata->alt == '#' && str[0] != '0')
	if (pfdata->alt == '#' && str[0] != '0' && str[0])
	{
		tstr = str;
		str = ft_strjoin("0x", str);
		str[1] = c;
		free(tstr);
	}
	return(str);
}