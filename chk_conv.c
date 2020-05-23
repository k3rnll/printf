#include "ft_printf.h"

void 	chk_conv(t_pfdata *pfdata)
{
	int 	k;

	k = 0;
	while (pfdata->conversion[k] != '\0')
	{
		if (pfdata->format[pfdata->i] == pfdata->conversion[k])
		{
			chk_prec(pfdata);
			reparse(pfdata);
			digits(pfdata);
		}
		k++;
	}
}