/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:06:06 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/08 11:52:30 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	process(const char *s, int *i, va_list ap)
{
	if (s[*i] == '%' && s[*i + 1])
	{
		(*i)++;
		return (handle_format(s[*i], ap));
	}
	if (s[*i] == '%' && s[*i + 1] == '\0')
		return (-1);
	return (print_char(s[*i]));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		printed;
	int		ret;

	if (!s)
		return (-1);
	printed = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		ret = process(s, &i, ap);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		printed += ret;
		i++;
	}
	va_end(ap);
	return (printed);
}
