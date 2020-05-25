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
	size_t 		prec;
//	int 		prec;
	size_t 		dotprec;
//	int 		dotprec;
	char 		alt;
	char 		align;
	char 		zero;
	char 		space;
	char 		plus;
	char 		dot;
	size_t 		i;
	size_t		len;
	long long 		x;

}				t_pfdata;

int			ft_printf(char *format, ...);
void		ft_putnstr(char const *s, size_t n);
void 		fill_space(t_pfdata *pfdata, char c);
void 		init(t_pfdata *pflist);
void 		reinit(t_pfdata *pfdata);
void 		parse(t_pfdata *pflist);
size_t		ft_putptr(void *ptr);
void 		chk_flag(t_pfdata *pfdata);
int 		chk_conv(t_pfdata *pfdata);
void		chk_mod(t_pfdata *pfdata);
void		chk_prec(t_pfdata *pfdata);
void 		domod(t_pfdata *pfdata);
void 		reparse(t_pfdata *pfdata);
void 		digits(t_pfdata *pfdata);
char		*llitoa(long long int n, t_pfdata *pfdata);
char		*ft_utoa(unsigned long long u, t_pfdata *pfdata);
char 		*utohex(unsigned long long n, char c, t_pfdata *pfdata);
char 		*otoa(unsigned int n, t_pfdata *pfdata);

#endif
