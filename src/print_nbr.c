/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:05:36 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 12:03:24 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
		if (print_char('-') == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (print_nbr(n / 10) == -1)
			return (-1);
	}
	if (print_char(n % 10 + '0') == -1)
		return (-1);
	return (printed);
}
