#include "ft_printf.h"

void 	chk_aster(t_pfdata *pfdata)
{
	size_t		k;

		k = pfdata->i - 1;
		while ((pfdata->format[k] == '*' || ft_isdigit(pfdata->format[k])) && pfdata->format[k] != '%')
			k--;
		if (pfdata->format[k] == '.')
		{
			pfdata->dot = '.';
			while ((ft_strchr("*.", pfdata->format[k]) || ft_isdigit(pfdata->format[k])) && pfdata->format[k] != '%')
				k--;
			while(pfdata->format[++k] != '.')
				pfdata->prec = pfdata->format[k] == '*' ? va_arg(pfdata->args, int) : 0;
			while(k < pfdata->i)
			{
				pfdata->dotprec = pfdata->format[k] == '*' ? va_arg(pfdata->args, int) : 0;
				k++;
			}
		}
		else
			while(++k < pfdata->i)
				pfdata->prec = pfdata->format[k] == '*' ? va_arg(pfdata->args, int) : 0;
}

void	chk_prec(t_pfdata *pfdata)
{
	chk_aster(pfdata);
	size_t		k;

		k = pfdata->i - 1;
		while (ft_isdigit(pfdata->format[k]) && pfdata->format[k] != '%')
			k--;
		if (pfdata->dot)
		{
			if (ft_isdigit(pfdata->format[k + 1]))
				pfdata->dotprec = ft_atoi(&(pfdata->format[k + 1]));
			while (pfdata->format[k] != '.')
				k--;
			k--;
			while (ft_isdigit(pfdata->format[k]) && pfdata->format[k] != '%')
				k--;
			if (ft_isdigit(pfdata->format[k + 1]))
				pfdata->prec = ft_atoi(&(pfdata->format[k + 1]));
			if (!pfdata->zero)
				pfdata->zero = pfdata->prec ? 0 : 1;
		}
		else if (ft_isdigit(pfdata->format[k + 1]))
			pfdata->prec = ft_atoi(&(pfdata->format[k + 1]));
	pfdata->align = pfdata->prec < 0 ? '-' : pfdata->align;
	pfdata->prec = !pfdata->dot && pfdata->prec < 0 ? -pfdata->prec : pfdata->prec;
//	pfdata->dotprec = pfdata->dotprec < 0 ? 0 : pfdata->dotprec;
//	pfdata->dotprec = pfdata->dotprec < 0 ? -pfdata->dotprec : pfdata->dotprec;
}