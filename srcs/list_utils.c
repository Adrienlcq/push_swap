/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:47:18 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/28 15:22:51 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Fonction pour init les listes */
t_stack	*ft_init_stack(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

/* Fonction pour ajouter un nombre dans la liste */
int	ft_add_list(t_stack *a, int nbr)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (0);
	new->nb = nbr;
	new->next = NULL;
	if (a->first == NULL)
	{
		a->first = new;
		a->last = new;
	}
	else
	{
		a->last->next = new;
		a->last = new;
	}
	return (1);
}

int	ft_strlen_list(t_stack *s)
{
	int	i;
	t_node *node;

	node = s->first;
	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

/* Fonction qui permet de free les lists **/
t_stack	*ft_delete_list(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->first;
	while (node != NULL)
	{
		tmp = node;
		node = tmp->next;
		free(tmp);
	}
	free(stack);
	return (NULL);
}

int	is_min(t_stack *s)
{
	t_node *node;
	int	min;

	node = s->first;
	min = node->nb;
	if (node->next)
		node = node->next;
	while (node != NULL)
	{
		if (min > node->nb)
			min = node->nb;
		node = node->next;
	}
	return (min);
}