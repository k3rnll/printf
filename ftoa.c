#include "ft_printf.h"

char 	*zerostr(size_t i)
{
	char 	*str;

	str = ft_strnew(i);
	while (i)
	{
		i--;
		str[i] = '0';
	}
	return(str);
}

char 	*ftoa(long double f, t_pfdata *pfdata)
{
	char	*str;
	char 	*str1;
	char 	*str2;
	char 	*res;
	int 	l;
	int 	i;
	long double 	k;
	int 	dotprec;

	dotprec = pfdata->dotprec ? pfdata->dotprec : 6;
	pfdata->dotprec = 0;
	str = llitoa(f, pfdata);
	str1 = ft_strjoin(str, ".");
	free(str);
	f = f < 0 ? -f : f;
	while (f > 1 && f > 0)
		f = f - (long int)f;
	i = 0;
	while (i < 18 && i < dotprec) {
		f = f * 10;
		i++;
	}
//	str2 = llitoa(f, pfdata);
	k = f - (long int) f;
	if ((long int)(k * 10) > 4)
		f = f + 1;
	str2 = llitoa(f, pfdata);
	if (i < dotprec) {
		str = str2;
		str2 = ft_strjoin(str, zerostr(dotprec - i));
		free(str);
	}
	res = ft_strjoin(str1, str2);
//	pfdata->dotprec = 40;
	free (str1);
	free (str2);
	return(res);
}

