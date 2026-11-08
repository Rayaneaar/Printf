/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:50:44 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/07 17:55:39 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	recursion_helper(unsigned long long n, char *base, int base_len)
{
	if (n >= base_len)
		return (recursion_helper(n / base_len, base, base_len));
	print_char(base[n % base_len]);
}

int	ft_putnbr_base(void *ptr, char *base)
{
	unsigned long long	base_len;
	int					i;
	int					len;
	unsigned long long	n;

	n = (unsigned long long)ptr;
	i = 0;
	len = 1;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		print_char('-');
		n *= -1;
		len++;
	}
	recursion_helper(n, base, base_len);
	return (len);
}

int	main(void)
{
	int	b;
	int	*a;

	b = 23;
	a = &b;
	ft_putnbr_base(a, "0123456789abcdef");
}
