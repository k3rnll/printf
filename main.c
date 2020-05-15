#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char	*str;
	int		i;
	unsigned int	u;
	char 	c;
	int 	k;

	i = -1;
	u = (unsigned int)i;
	c = 'a';
//	k = NULL;
	//i = 256;
	str = "Hello World!";
	ft_printf("%u", -1);//	printf("myint: %d\nmychar: %c\n%n", i, c, &k);
//	i = *k;
//	printf("%d\n", k);
	return (0);
}
