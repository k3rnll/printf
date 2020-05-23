#include <stdio.h>
#include "ft_printf.h"

int		main(void) {
	char *str;
	int i;
	long long int u;
	char c;
	int k;

	i = 45647;
	u = 9223372036854775807;
	c = 'a';
//	k = NULL;
	//i = 256;
	str = "Hello World!";
	ft_printf("%#x", 0);
	//	printf("%llu", 4999999999);
	return(0);
}
