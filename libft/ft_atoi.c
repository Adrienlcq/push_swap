/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:38:08 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/08 16:08:55 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_atoi() convertit le début de la chaîne
** pointée par str en entier de type int.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	negative = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	if (result < 0 && negative == 1)
		return (-1);
	else if (result < 0 && negative == -1)
		return (0);
	return (result * negative);
}
/* 
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Errorrrrrrrrrrrrrr\n");
		return (1);
	}
	printf("%d\n", ft_atoi(av[1]));
	return 0;
} */
