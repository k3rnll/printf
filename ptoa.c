#include "ft_printf.h"

char 		*convert_p(char *str, t_pfdata *pfdata)
{
	char 	*tstr;
	int 	i;

	i = 0;
//	tstr = ft_strnew(18);
	while (str[i] == '0')
		i++;
	if (pfdata->dotprec > 16 - i)
		i = 16 - pfdata->dotprec;
	tstr = i == 16 ? ft_strjoin( "0x", "0") : ft_strjoin("0x", &str[i]);
	free(str);
//	write(1, "0x", 2);
//	ft_putstr(&str[i]);
//	i = ft_strlen(&str[i]) + 2;
	return (tstr);
}

char		*ft_ptoa(void *ptr, t_pfdata *pfdata)
{
	char 	*str;
	int 	k;
	unsigned long	i;
	unsigned long	tmp;

	str = ft_strnew(16);
	k = 0;
	i = (unsigned long)ptr;
	while(k < 16)
	{
		tmp = i & 0xF000000000000000;
		tmp = tmp >> 60;
		if (tmp < 10)
			str[k] = (char)(tmp + 48);
		else
			str[k] = (char)(tmp + 87);
		i = i << 4;
		k++;
	}

	return(convert_p(str, pfdata));
}