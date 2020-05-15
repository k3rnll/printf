#include "ft_printf.h"

void 	digits(t_pfdata *pfdata)
{
	char 	*str;

	if (pfdata->format[pfdata->i] == 'd')
	{
		str = ft_itoa(va_arg(pfdata->args, int));
		ft_putstr(str);
		pfdata->i++;
		pfdata->len = pfdata->len + ft_strlen(str);
	}
	if (pfdata->format[pfdata->i] == 'u')
	{
		str = ft_utoa(va_arg(pfdata->args, int));
		ft_putstr(str);
		pfdata->i++;
		pfdata->len = pfdata->len + ft_strlen(str);
	}
}