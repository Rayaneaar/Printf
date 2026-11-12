/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:17:26 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/08 11:53:02 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_ptr_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_hexa_ptr(unsigned long n)
{
	char			*hexa;
	unsigned long	original;

	hexa = "0123456789abcdef";
	original = n;
	if (n >= 16)
	{
		if (print_hexa_ptr(n / 16) == -1)
			return (-1);
	}
	if (print_char(hexa[n % 16]) == -1)
		return (-1);
	return (get_ptr_len(original));
}

int	print_ptr(void *ptr)
{
	unsigned long	pointer;
	int				ret;

	if (!ptr)
		return (print_str("(nil)"));
	pointer = (unsigned long)ptr;
	ret = print_str("0x");
	if (ret == -1)
		return (-1);
	ret = print_hexa_ptr(pointer);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
