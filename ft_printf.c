#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_pfdata	*pfdata;
	int 		i;

	if (!(pfdata = (t_pfdata*)malloc(sizeof (t_pfdata))))
		return (-1);
	init(pfdata);
	if (format)
	{
		pfdata->format = format;
		va_start(pfdata->args, format);
		parse(pfdata);
		va_end(pfdata->args);
	}
	i = (pfdata->len);
	free(pfdata);
	return(i);
}