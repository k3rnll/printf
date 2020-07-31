#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char 	c;
	float 	f;
	char 	*str;
	c = 124 - 127;
	f = 1.15 / 10;

	printf("{%10.40f}\n", 444646.6465424242242);
	ft_printf("{%10.40f}", 444646.6465424242242);
	//	ft_printf("%d\n", f);
//	ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	return(0);
}
//