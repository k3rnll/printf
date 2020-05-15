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
			chk_conv(pfdata);
			continue;
		}

//		write(1, &(pfdata->format[pfdata->i]), 1);

		if (pfdata->format[pfdata->i] == '\0')
			break;
		ft_putchar(pfdata->format[pfdata->i++]);
		pfdata->len++;
	}
}