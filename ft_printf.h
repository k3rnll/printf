#ifndef PRINTF_H
#define PRINTF_H
#include "./libft/libft.h"
#include <stdarg.h>

typedef struct	s_pfdata
{

	const char 	*format;
	va_list 	args;
	char 		*conversion;
	char 		*flags;
	char 		mod[2];
	int 		prec;
	char 		alt;
	char 		align;
	char 		zero;
	char 		space;
	char 		plus;
	size_t 		i;
	size_t		len;
	long long 		x;

}				t_pfdata;

int			ft_printf(char *format, ...);
void 		init(t_pfdata *pflist);
void 		parse(t_pfdata *pflist);
size_t		ft_putptr(void *ptr);
void 		chk_flag(t_pfdata *pfdata);
void 		chk_conv(t_pfdata *pfdata);
void		chk_mod(t_pfdata *pfdata);
void		chk_prec(t_pfdata *pfdata);
void 		domod(t_pfdata *pfdata);
void 		reparse(t_pfdata *pfdata);
void 		digits(t_pfdata *pfdata);
char		*llitoa(long long int n);
char		*ft_utoa(unsigned long long u, t_pfdata *pfdata);
char 		*utohex(unsigned long long n, char c, t_pfdata *pfdata);
char 		*otoa(unsigned int n);

#endif
