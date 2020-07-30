#include "ft_printf.h"

void 	chk_flag(t_pfdata *pfdata)
{
	while (ft_strchr(pfdata->flags, pfdata->format[pfdata->i]))
	{
		pfdata->alt = (pfdata->format[pfdata->i] == '#') ? '#' : pfdata->alt;
		pfdata->align = (pfdata->format[pfdata->i] == '-') ? '-' : pfdata->align;
		pfdata->zero = (pfdata->format[pfdata->i] == '0') ? 1 : pfdata->zero;
		pfdata->space = (pfdata->format[pfdata->i] == ' ') ? ' ' : pfdata->space;
		pfdata->plus = (pfdata->format[pfdata->i] == '+') ? '+' : pfdata->plus;
		pfdata->dot = (pfdata->format[pfdata->i] == '.') ? '.' : pfdata->dot;
//		pfdata->prec = (pfdata->format[pfdata->i] == '*') ? va_arg(pfdata->args, int) : 0;
		pfdata->i++;
	}
}