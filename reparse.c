#include "ft_printf.h"

void 	fill_space(t_pfdata *pfdata, char c)
{
	while (pfdata->prec > 0)
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
	char 	t;
	size_t	len;

	str = NULL;
	if (pfdata->format[pfdata->i] == 'c' || pfdata->format[pfdata->i] == '%')
	{
		len = 1;
		t = pfdata->zero && !pfdata->align ? '0' : ' ';
		c = pfdata->format[pfdata->i] == 'c' ? (char)va_arg(pfdata->args, int) : '%';
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		pfdata->align == '-' ? ft_putchar(c) : fill_space(pfdata, t);
		pfdata->align == '-' ? fill_space(pfdata, t) : ft_putchar(c);
		if (c == '%' && pfdata->format[pfdata->i + 1] && ft_strchr("scpdiouxXf", pfdata->format[pfdata->i + 1])) {
			pfdata->i++;
			pfdata->len++;
			ft_putchar(pfdata->format[pfdata->i]);
		}
		pfdata->i++;
		pfdata->len++;
	}
	if (pfdata->format[pfdata->i] == 's')
	{
		if(!(str = va_arg(pfdata->args, char*)))
			str = "(null)";
		len = ft_strlen(str);
		pfdata->prec = pfdata->prec < 0 ? -pfdata->prec : pfdata->prec;
		len = (pfdata->dot && pfdata->dotprec < len) ? pfdata->dotprec : len;
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		pfdata->align == '-' ? ft_putnstr(str, len) : fill_space(pfdata, ' ');
		pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putnstr(str, len);
		pfdata->i++;
		pfdata->len += len;
	}
	if (pfdata->format[pfdata->i] == 'p')
	{
		str = ft_ptoa(va_arg(pfdata->args, int*), pfdata);
		len = ft_strlen(str);
		len = (pfdata->dot && pfdata->dotprec < 1 && pfdata->dotprec >= 0) ? 2 : len;
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		pfdata->align == '-' ? ft_putnstr(str, len) : fill_space(pfdata, ' ');
		pfdata->align == '-' ? fill_space(pfdata, ' ') : ft_putnstr(str, len);
		pfdata->i++;
		pfdata->len += len;
		free(str);
	}

}

