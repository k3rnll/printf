#include "ft_printf.h"

void 	init(t_pfdata *pfdata)
{
	pfdata->conversion = "%scpdu";
	pfdata->len = 0;
	pfdata->i = 0;
}