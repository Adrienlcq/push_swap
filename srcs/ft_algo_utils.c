/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:40:25 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 15:13:19 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rename_list(t_stack *copy, t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		count;

	i = a->first;
	j = copy->first;
	count = 0;
	while (j != NULL)
	{
		if (i->nb != j->nb)
		{
			j = j->next;
			count++;
		}
		else
		{
			i->nb = count;
			if (!i->next)
				return ;
			i = i->next;
			j = copy->first;
			count = 0;
		}
	}
}

/* Pour trier la copie */
t_stack	*ft_sort_copy(t_stack *copy)
{
	t_node	*i;
	int		tmp;

	i = copy->first;
	while (i != copy->last)
	{
		if (i->nb > i->next->nb)
		{
			tmp = i->nb;
			i->nb = i->next->nb;
			i->next->nb = tmp;
			i = copy->first;
		}
		else
			i = i->next;
	}
	return (copy);
}

void	ft_copy_list(t_stack *a, t_stack *copy)
{
	t_node	*node;

	node = a->first;
	while (node != NULL)
	{
		if (ft_add_list(copy, node->nb) == 0)
			return ;
		node = node->next;
	}
}

void	ft_copy_list_min(t_stack *a, t_stack *copy)
{
	t_node	*node;
	int		min;

	node = a->first;
	min = is_min(a);
	while (node != NULL)
	{
		if (ft_add_list(copy, node->nb) == 0)
			return ;
		if (node->nb == min)
			break ;
		node = node->next;
	}
}
