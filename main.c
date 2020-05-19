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
//	printf("%d\n", sizeof(i));
//	printf("%d", sizeof(u));
	ft_printf("%x\n", -42);
//	ft_printf("%llx", 9223372036854775807);
	return(0);
}
