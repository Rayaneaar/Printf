/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:42:44 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 11:49:53 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_ptr(void *ptr)
{
	unsigned long long	pointer;
	int					printed;

	printed = 2;
	if (!ptr)
		return (print_str("(nil)"));
	pointer = (unsigned long long)ptr;
	print_str("0x");
	printed += print_hex_ptr(pointer);
	return (printed);
}
