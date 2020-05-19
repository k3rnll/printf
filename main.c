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
	ft_printf("%u\n", 1);
	printf("%u\n------------------\n", 1);
	ft_printf("%u\n", 5);
	printf("%u\n------------------\n", 5);
	ft_printf("%u\n", 4294967296);
	printf("%u\n------------------\n", 4294967296);
	ft_printf("%u\n", 4294967295);
	printf("%u\n", 4294967295);
	printf("------------------\n");
	ft_printf("%lu\n", -42);
	printf("%lu", -42);
	//	ft_printf("%llu\n", 4999999999);
//	printf("%llu", 4999999999);
	return(0);
}
