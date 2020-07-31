#include "ft_printf.h"

void 	disp_digit(char *str, t_pfdata *pfdata)
{
	if (pfdata->align == '-')
	{
		ft_putstr(str);
		fill_space(pfdata, ' ');
	}
	else
	{
		str[0] == '-' && pfdata->zero ? ft_putchar('-') : 0;
		if (str[0] != '-' && (pfdata->plus || pfdata->space) && pfdata->format[pfdata->i] != 'u' && !pfdata->dotprec)
		{
			pfdata->plus ? write(1, "+", 1) : write(1, " ", 1);
			pfdata->len++;
			pfdata->prec = pfdata->zero && pfdata->prec > 0 ? pfdata->prec - 1 : pfdata->prec;
		}
		pfdata->alt && pfdata->zero ? ft_putnstr(str, 2) : 0;
//		pfdata->alt && pfdata->zero && !pfdata->dot ? ft_putnstr(str, 2) : 0;

		pfdata->zero && pfdata->dotprec < 1 ? fill_space(pfdata, '0') : fill_space(pfdata, ' ');
//		pfdata->zero ? fill_space(pfdata, '0') : fill_space(pfdata, ' ');

		if (str[0] == '-' && pfdata->zero)
			ft_putstr(&str[1]);
		else if (pfdata->alt && pfdata->zero)
			ft_putstr(&str[2]);
		else
			ft_putstr(str);
	}
}

void 	digits(t_pfdata *pfdata)
{
	char 	*str;
	size_t	len;

	str = NULL;
	if (ft_strchr("diouxX", pfdata->format[pfdata->i]))
		domod(pfdata);
	if (pfdata->format[pfdata->i] == 'f' && pfdata->format[pfdata->i-1] != 'L')
		str = ftoa(va_arg(pfdata->args, double), pfdata);
	if (pfdata->format[pfdata->i] == 'f' && pfdata->format[pfdata->i-1] == 'L')
		str = ftoa(va_arg(pfdata->args, long double), pfdata);
	if (pfdata->format[pfdata->i] == 'd' || pfdata->format[pfdata->i] == 'i')
		str = llitoa(pfdata->x, pfdata);
	if (pfdata->format[pfdata->i] == 'o')
		str = otoa(pfdata->x, pfdata);
	if (pfdata->format[pfdata->i] == 'u')
		str = ft_utoa(pfdata->x, pfdata);
	if (pfdata->format[pfdata->i] == 'x' || pfdata->format[pfdata->i] == 'X')
		str = utohex(pfdata->x, pfdata->format[pfdata->i], pfdata);
	if (str) {
		len = ft_strlen(str);
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		disp_digit(str, pfdata);
		pfdata->i++;
		pfdata->len += len;
		free(str);
	}
}