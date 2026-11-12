/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:24:18 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/08 11:42:20 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	handle_format(char spec, va_list args)
{
	int	ret;

	ret = 0;
	if (spec == 'c')
		ret = (print_char(va_arg(args, int)));
	else if (spec == 's')
		ret = (print_str(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		ret = (print_nbr(va_arg(args, int)));
	else if (spec == 'x')
		ret = (print_hexa(va_arg(args, unsigned int), 2));
	else if (spec == 'u')
		ret = (print_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'X')
		ret = (print_hexa(va_arg(args, unsigned int), 1));
	else if (spec == 'p')
		ret = (print_ptr(va_arg(args, void *)));
	else if (spec == '%')
		ret = (print_char('%'));
	return (ret);
}
