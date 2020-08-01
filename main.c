#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char 	*str;

	str = "hello";
	printf("%.*p\n", -3, str);
	ft_printf("%.*p", -3, str);
	return(0);
}
//