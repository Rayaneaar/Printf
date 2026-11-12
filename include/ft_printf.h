/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:17:15 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/10 15:17:15 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_char(char c);
int		print_nbr(int n);
int		print_str(char *s);
int		handle_format(char spec, va_list args);
int		print_hexa(unsigned int n, int type);
int		print_unsigned(unsigned int n);
int		print_ptr(void *ptr);

#endif