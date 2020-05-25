#include "ft_printf.h"

void 	fill_space(t_pfdata *pfdata, char c)
{
	while (pfdata->prec)
	{
		ft_putchar(c);
		pfdata->len++;
		pfdata->prec--;
	}
}

void 	reparse(t_pfdata *pfdata)
{
	char 	*str;
	char 	c;
	size_t	len;

	str = NULL;
	if (pfdata->format[pfdata->i] == 'c' || pfdata->format[pfdata->i] == '%')
	{
		len = 1;
		c = pfdata->format[pfdata->i] == 'c' ? (char)va_arg(pfdata->args, int) : '%';
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		pfdata->align == '-' ? ft_putchar(c) : fill_space(pfdata, ' ');
		pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putchar(c);
		pfdata->i++;
		pfdata->len++;
	}
	if (pfdata->format[pfdata->i] == 's')
	{
		if(!(str = va_arg(pfdata->args, char*)))
			str = "(null)";
		len = ft_strlen(str);
		len = (pfdata->dotprec > 0 && pfdata->dotprec < len) ? pfdata->dotprec : len;
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		pfdata->align == '-' ? ft_putnstr(str, len) : fill_space(pfdata, ' ');
		pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putnstr(str, len);
		pfdata->i++;
		pfdata->len += len;
	}
	if (pfdata->format[pfdata->i] == 'p')
	{
		pfdata->len = pfdata->len + (ft_putptr(va_arg(pfdata->args, int*)));
		pfdata->i++;
	}
}

