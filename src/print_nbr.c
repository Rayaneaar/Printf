/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:05:36 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 17:17:00 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_printed_numbers(int nbr)
{
	int		printed;
	long	n;

	printed = 1;
	n = nbr;
	if (n < 0)
	{
		printed++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		printed++;
	}
	return (printed);
}
int	print_nbr(int nbr)
{
	long	n;
	int		sign;
	int		printed;

	n = nbr;
	sign = 1;
	printed = get_printed_numbers(n);
	if (n < 0)
	{
		print_char('-');
		n = -n;
	}
	if (n >= 10)
		print_nbr(n / 10);
	print_char(n % 10 + '0');
	return (printed);
}
