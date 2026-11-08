/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:24:18 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 11:50:06 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_format(char spec, va_list args)
{
	if (spec == 'c')
		return (print_char(va_arg(args, int)));
	else if (spec == 's')
		return (print_str(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (spec == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	else if (spec == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	else if (spec == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (spec == '%')
		return (print_char('%'));
	return (0);
}
