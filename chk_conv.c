#include "ft_printf.h"

int 	chk_conv(t_pfdata *pfdata)
{
	int 	k;

	while (pfdata->format[pfdata->i])
	{
		k = 0;
		while (pfdata->conversion[k] != '\0') {
			if (pfdata->format[pfdata->i] == pfdata->conversion[k]) {
				chk_prec(pfdata);
				reparse(pfdata);
				digits(pfdata);
				return (0);
			}
			k++;
		}
		if (pfdata->format[pfdata->i] == '\0')
			break;
//		ft_putchar(pfdata->format[pfdata->i]);
		pfdata->i++;
	}
	return(0);
}