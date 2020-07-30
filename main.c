#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int 	i;
	printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	return(0);
}
//