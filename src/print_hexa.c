/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:55:31 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/08 11:11:16 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	get_hexa_len(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_hexa(unsigned int n, int type)
{
	char			*hexa;
	unsigned int	original;

	hexa = "0123456789abcdef";
	original = n;
	if (type == 1)
		hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (print_hexa(n / 16, type) == -1)
			return (-1);
	}
	if (print_char(hexa[n % 16]) == -1)
		return (-1);
	return (get_hexa_len(original));
}
