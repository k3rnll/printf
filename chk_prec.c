#include "ft_printf.h"

void	chk_prec(t_pfdata *pfdata)
{
	size_t		k;

	k = pfdata->i - 1;
	while (ft_isdigit(pfdata->format[k]) && pfdata->format[k] != '%')
		k--;
	pfdata->prec = ft_atoi(&(pfdata->format[k+1]));
}