/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:37:46 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/08 11:40:53 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_len_unsigned(unsigned int n)
{
	int	printed;

	printed = 1;
	while (n >= 10)
	{
		n /= 10;
		printed++;
	}
	return (printed);
}

int	print_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		if (print_unsigned(n / 10) == -1)
			return (-1);
	}
	if (print_char(n % 10 + '0') == -1)
		return (-1);
	return (get_len_unsigned(n));
}
