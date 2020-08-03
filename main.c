#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	printf("%5c\n", 42);
	ft_printf("%5c", 42);
	return(0);
}
//