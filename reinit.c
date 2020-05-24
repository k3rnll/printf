#include "ft_printf.h"

void 	reinit(t_pfdata *pfdata)
{
	pfdata->mod[0] = 0;
	pfdata->mod[1] = 0;
	pfdata->prec = 0;
	pfdata->dotprec = 0;
	pfdata->alt = 0;
	pfdata->align = 0;
	pfdata->zero = 0;
	pfdata->space = 0;
	pfdata->plus = 0;
}