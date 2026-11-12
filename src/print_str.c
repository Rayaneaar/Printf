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

#include "../include/ft_printf.h"

int	print_str(char *s)
{
	int	i;

	if (!s)
		return (print_str("(null)"));
	i = 0;
	while (s[i])
	{
		if (print_char(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
