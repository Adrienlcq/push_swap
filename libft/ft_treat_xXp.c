/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:33:24 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/10 12:34:26 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* treat x and X */
int	ft_hex_putnbr(unsigned int n, char *hexa)
{
	int		i;

	i = 0;
	if (n >= 16)
		i += ft_hex_putnbr((n / 16), hexa);
	i += ft_putchar(hexa[(n % 16)]);
	return (i);
}

/* treat p */
int	ft_treat_ptr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_point_print(n, hex);
	return (i);
}

int	ft_point_print(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_point_print((n / 16), hex);
	i += ft_putchar(hex[(n % 16)]);
	return (i);
}
