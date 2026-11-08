/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:06:06 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 17:19:20 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stddef.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	printed = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			printed += handle_format(s[++i], ap);
		else
			printed += print_char(s[i]);
		i++;
	}
	va_end(ap);
	return (printed);
}
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		a;
	int		*p;
	char	*itoa;
	size_t	len;

	a = 10;
	p = &a;
	print_ptr(p);
	printf("\n");
	printf("test=> %p\n", p);
}
