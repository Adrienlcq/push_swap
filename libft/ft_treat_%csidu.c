/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_%csidu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <adrien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:22:54 by adlecler          #+#    #+#             */
/*   Updated: 2022/03/01 20:06:44 by adrien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* treat % */
int	ft_treat_percentage(char c)
{
	write(1, &c, 1);
	return (1);
}

/* treat c */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* treat s */
int	ft_treat_s(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

/* treat i and d */
int	ft_putnbr(int n)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

/* treat u */
int	ft_uputnbr(unsigned int n)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	if (nbr >= 10)
	{
		i += ft_uputnbr(n / 10);
		i += ft_uputnbr(n % 10);
	}
	else
	{
		i += ft_putchar(nbr + '0');
	}
	return (i);
}
