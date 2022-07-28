/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:08:11 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/23 15:26:00 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 24 lignes // retourne 1 en cas d'erreur et 0 si ok
int	check_arg(char *s)
{
	int	i;

	if (s[0] == '+' || s[0] == '-')
	{
		i = 1;
		if (!s[i])
			return (1); // dans le cas d'un argument comme "-" ou "+"
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

// 25 lignes // recupere av[i] en int pour le comparer a INT_MIN et INT_MAX
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

/* Fonction pour checker si la liste passe en parametre est trie */
int	ft_is_sorted(t_stack *stack)
{
	t_node *node;

	node = stack->first;
	while (node->next != NULL)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	return (1);
}