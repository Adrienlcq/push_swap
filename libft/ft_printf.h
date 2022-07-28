/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:05:04 by adlecler          #+#    #+#             */
/*   Updated: 2022/06/21 15:56:42 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

/* struct */
typedef struct s_data
{
	int		ret;
	va_list	args;
}				t_data;

/* corps ft_printf */
int		ft_printf(const char *format, ...);
void	ft_write_with_increment(t_data *data, char c);
void	ft_type(t_data *data, char c);
int		is_ok(char c);

/* treat cspdiuxX% */
int		ft_treat_percentage(char c);
int		ft_putchar(char c);
int		ft_treat_s(char *str);
int		ft_putnbr(int n);
int		ft_uputnbr(unsigned int n);
int		ft_hex_putnbr(unsigned int n, char *hexa);
int		ft_treat_ptr(unsigned long n, char *hex);
int		ft_point_print(unsigned long n, char *hex);
#endif
