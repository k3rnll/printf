#include "ft_printf.h"

void 	chk_flag(t_pfdata *pfdata)
{
	while (ft_strchr(pfdata->flags, pfdata->format[pfdata->i]))
	{
		pfdata->alt = (pfdata->format[pfdata->i] == '#') ? '#' : 0;
		pfdata->align = (pfdata->format[pfdata->i] == '-') ? '-' : 0;
		pfdata->zero = (pfdata->format[pfdata->i] == '0') ? 1 : 0;
		pfdata->space = (pfdata->format[pfdata->i] == ' ') ? ' ' : 0;
		pfdata->plus = (pfdata->format[pfdata->i] == '+') ? '+' : 0;
		pfdata->i++;
	}
}