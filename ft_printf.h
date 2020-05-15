#ifndef PRINTF_H
#define PRINTF_H
#include "./libft/libft.h"
#include <stdarg.h>

typedef struct	s_pfdata
{

	const char 	*format;
	va_list 	args;
	char 		*conversion;
	size_t 		i;
	size_t		len;

}				t_pfdata;

int			ft_printf(char *format, ...);
void 		init(t_pfdata *pflist);
void 		parse(t_pfdata *pflist);
size_t		ft_putptr(void *ptr);
void 		chk_conv(t_pfdata *pfdata);
void 		reparse(t_pfdata *pfdata);
void 	digits(t_pfdata *pfdata);
char		*ft_utoa(unsigned int u);

#endif
