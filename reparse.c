#include "ft_printf.h"

void 	reparse(t_pfdata *pfdata)
{
	char 	*str;

	if (pfdata->format[pfdata->i] == 'c')
	{
		ft_putchar((char)va_arg(pfdata->args, int));
		pfdata->i++;
		pfdata->len++;
	}
	if (pfdata->format[pfdata->i] == 's')
	{
		if(!(str = va_arg(pfdata->args, char*)))
			str = "(null)";
		ft_putstr(str);
		pfdata->i++;
		pfdata->len = pfdata->len + ft_strlen(str);
	}
	if (pfdata->format[pfdata->i] == 'p')
	{
		pfdata->len = pfdata->len + (ft_putptr(va_arg(pfdata->args, int*)));
		pfdata->i++;
	}
}

