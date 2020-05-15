#include <unistd.h>
#include "./libft/libft.h"

int 		prnt_ptr(char *ptr)
{
	int 	i;

	i = 0;
	while (ptr[i] == '0')
		i++;
	write(1, "0x", 2);
	ft_putstr(&ptr[i]);
	i = ft_strlen(&ptr[i] + 2);
	return (i);
}

size_t		ft_putptr(void *ptr)
{
	char 	*str;
	size_t	len;
	int 	k;
	unsigned long	i;
	unsigned long	tmp;

	str = ft_strnew(16);
	k = 0;
	i = (unsigned long)ptr;
	while(k < 16)
	{
		tmp = i & 0xF000000000000000;
		tmp = tmp >> 60;
		if (tmp < 10)
			str[k] = (char)(tmp + 48);
		else
			str[k] = (char)(tmp + 87);
		i = i << 4;
		k++;
	}
	len = prnt_ptr(str);
	free(str);
	return (len);
}