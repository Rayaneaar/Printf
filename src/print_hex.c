/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:19:02 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 17:49:22 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_hex_lower(int nbr)
{
	unsigned int	n;
	char			hexa[] = "0123456789abcdef";

	n = (unsigned int)nbr;
	if (n >= 16)
		print_hex_lower(n / 16);
	print_char(hexa[n % 16]);
	return (get_printed_numbers(nbr));
}

int	print_hex_upper(int nbr)
{
	unsigned int	n;
	char			hexa[] = "0123456789ABCDEF";

	n = (unsigned int)nbr;
	if (n >= 16)
		print_hex_upper(n / 16);
	print_char(hexa[n % 16]);
	return (get_printed_numbers(nbr));
}

int	print_hex_ptr(unsigned long long n)
{
	char	hexa[] = "0123456789abcdef";

	if (n >= 16)
		print_hex_ptr(n / 16);
	print_char(hexa[n % 16]);
	return (get_printed_numbers(n));
}
