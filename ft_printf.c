#include <stdarg.h>
#include "ft_printf.h"

int		ft_print(char *format, va_list ap, int *len)
{
	int		d;
	char	c;
	int 	*i;
	char	*str;

	if (*(format + 1) == 'c')
		{
			c = (char)va_arg(ap, int);
			ft_putchar(c);
			return(*len + 1);
		}
	else if (*(format + 1) == 'd')
		{
			d = va_arg(ap, int);
			str = ft_itoa(d);
			ft_putstr(str);
			d = ft_strlen(str);
			free(str);
			return(*len + d);
		}
	else if (*(format + 1) == 'n')
	{
		i = va_arg(ap, int*);
		*i = *len;
		return (*len);
	}
	else if (*(format + 1) == 'p')
	{
//		i = va_arg(ap, int*);
		ft_putptr(va_arg(ap, int*));
		return (*len);
	}
	return (0);
}

int		ft_printf(char *format, ...)
{
	t_pfdata	*pfdata;
//	va_list 	ap;

	if (!(pfdata = (t_pfdata*)malloc(sizeof (t_pfdata))))
		return (-1);
	pfdata->format = format;
	if (format)
	{
		init(pfdata);
		va_start(pfdata->args, format);
		parse(pfdata);
		va_end(pfdata->args);
		return(pfdata->len);
	}
	return(pfdata->len);
}