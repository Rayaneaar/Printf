/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:02:26 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 09:03:33 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (print_str("(null)"));
	while (s[i])
	{
		print_char(s[i]);
		i++;
	}
	return (i);
}
