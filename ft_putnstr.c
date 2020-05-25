#include "ft_printf.h"

void	ft_putnstr(char const *s, size_t n)
{
	if (s)
	{
		while (*s && n)
		{
			write (1, &*s, 1);
			n--;
			s++;
		}
	}
}
