#include "ft_printf.h"

void 	digits(t_pfdata *pfdata)
{
	char 	*str;
	size_t	len;

	str = NULL;
	if (ft_strchr("diouxX", pfdata->format[pfdata->i]))
		domod(pfdata);
	if (pfdata->format[pfdata->i] == 'd' || pfdata->format[pfdata->i] == 'i')
		str = llitoa(pfdata->x);
//		str = ft_itoa(pfdata->x);
	if (pfdata->format[pfdata->i] == 'o')
		str = otoa(pfdata->x);
//		str = otoa(va_arg(pfdata->args, int));
	if (pfdata->format[pfdata->i] == 'u')
		str = ft_utoa(pfdata->x, pfdata);
		//		str = ft_utoa(va_arg(pfdata->args, int));
	if (pfdata->format[pfdata->i] == 'x' || pfdata->format[pfdata->i] == 'X')
		str = utohex(pfdata->x, pfdata->format[pfdata->i], pfdata);
//		str = utohex(va_arg(pfdata->args, int), pfdata->format[pfdata->i]);
	if (str) {
		len = ft_strlen(str);
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		if (pfdata->align == '-')
		{
			ft_putstr(str);
			while (pfdata->prec)
			{
				write(1, " ", 1);
				pfdata->len++;
				pfdata->prec--;
			}
		}
		else
		{
			if (str[0] == '-' && pfdata->zero)
				write(1, "-", 1);
			if (str[0] != '-' && (pfdata->plus || pfdata->space) && pfdata->format[pfdata->i] != 'u')
			{
				pfdata->plus ? write(1, "+", 1) : write(1, " ", 1);
					pfdata->len++;
				if(pfdata->zero)
					pfdata->prec--;
			}

			while (pfdata->prec)
			{
				(pfdata->zero == 1)? write(1, "0", 1) : write(1, " ", 1);
				pfdata->len++;
				pfdata->prec--;
			}
			 str[0] == '-' && pfdata->zero ? ft_putstr(&str[1]) : ft_putstr(str);
		}
		pfdata->i++;
		pfdata->len += len;
		free(str);
	}
}