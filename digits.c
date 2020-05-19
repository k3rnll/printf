#include "ft_printf.h"

void 	digits(t_pfdata *pfdata)
{
	char 	*str;

	str = NULL;
	doflag(pfdata);
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
		str = utohex(pfdata->x, pfdata->format[pfdata->i], sizeof(pfdata->x));
//		str = utohex(va_arg(pfdata->args, int), pfdata->format[pfdata->i]);
	if (str)
	{
		ft_putstr(str);
		pfdata->i++;
		pfdata->len = pfdata->len + ft_strlen(str);
		free(str);
	}
}