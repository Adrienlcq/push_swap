/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:08:11 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 13:04:16 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(char *s)
{
	int	i;

	if (s[0] == '+' || s[0] == '-')
	{
		i = 1;
		if (!s[i])
			return (1);
		while (s[i])
		{
			if (s[i] < '0' || s[i] > '9')
				return (1);
			i++;
		}
	}
	else
	{
		i = -1;
		while (s[++i])
		{
			if (s[i] < '0' || s[i] > '9')
				return (1);
		}
	}
	return (0);
}

long	ft_atol(const char *str)
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

int	ft_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->first;
	while (node->next != NULL)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	return (1);
}
