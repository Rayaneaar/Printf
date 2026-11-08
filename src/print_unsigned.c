/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 08:55:20 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 12:03:56 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_unsigned(unsigned int n)
{
	if (n >= 10)
		print_unsigned(n / 10);
	print_char(n % 10 + '0');
	return (get_printed_numbers(n));
}
