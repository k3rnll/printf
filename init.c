#include "ft_printf.h"

void 	init(t_pfdata *pfdata)
{
	pfdata->conversion = "%scpdiouxXf";
	pfdata->flags = "#0+- .*";
	pfdata->len = 0;
	pfdata->i = 0;
}