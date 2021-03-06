/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouise <clouise@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:52:45 by clouise           #+#    #+#             */
/*   Updated: 2020/08/03 22:53:01 by clouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char const *s, size_t n)
{
	if (s)
	{
		while (*s && n)
		{
			write(1, &*s, 1);
			n--;
			s++;
		}
	}
}
