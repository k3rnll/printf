#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	printf("{%.*s}\n", -5, "42");
	ft_printf("{%.*s}\n", -5, "42");
	return(0);
}
//