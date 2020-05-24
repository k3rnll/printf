#include "ft_printf.h"

void 	reparse(t_pfdata *pfdata)
{
	char 	*str;
	size_t	len;

	str = NULL;
	if (pfdata->format[pfdata->i] == 'c')
	{
		len = 1;
		pfdata->prec = (pfdata->prec > len) ? (pfdata->prec - len) : 0;
		if (pfdata->align == '-')
		{
			ft_putchar((char) va_arg(pfdata->args, int));
			while (pfdata->prec)
			{
				write(1, " ", 1);
				pfdata->len++;
				pfdata->prec--;
			}
		}
		else
		{
			while (pfdata->prec) {
				write(1, " ", 1);
				pfdata->len++;
				pfdata->prec--;
			}
			ft_putchar((char) va_arg(pfdata->args, int));
		}
		pfdata->i++;
		pfdata->len++;
	}
	if (pfdata->format[pfdata->i] == 's')
	{
		if(!(str = va_arg(pfdata->args, char*)))
			str = "(null)";
		len = ft_strlen(str);
		if (pfdata->dotprec > 0 && pfdata->dotprec < len)
		{
			str = ft_strsub(str, 0, pfdata->dotprec);
			len = pfdata->dotprec;
		}
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
			while (pfdata->prec) {
				write(1, " ", 1);
				pfdata->len++;
				pfdata->prec--;
			}
			ft_putstr(str);
		}
		pfdata->i++;
		pfdata->len = pfdata->len + len;
	}
	if (pfdata->format[pfdata->i] == 'p')
	{
		pfdata->len = pfdata->len + (ft_putptr(va_arg(pfdata->args, int*)));
		pfdata->i++;
	}
}

