#include "ft_printf.h"

void 	parse(t_pfdata *pfdata)
{
	int 	k;

	k = 0;
	while (pfdata->format[pfdata->i] != '\0')
	{
		if (pfdata->format[pfdata->i] == '%')
		{
			pfdata->i++;
			chk_flag(pfdata);
			chk_mod(pfdata);
			chk_conv(pfdata);
			continue;
		}
		if (pfdata->format[pfdata->i] == '\0')
			break;
		ft_putchar(pfdata->format[pfdata->i++]);
		pfdata->len++;
	}
}