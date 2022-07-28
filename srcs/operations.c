/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:07:38 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/28 15:32:12 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *s)
{
	int tmp;
	
	if (ft_strlen_list(s) >= 2)
	{
		tmp = s->first->nb;
		s->first->nb = s->first->next->nb;
		s->first->next->nb = tmp;
	}
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	t_node *new;

	if (!b || !b->first)
	{
		printf("JE PASSE ICI\n");
		return ;
	}
	new = b->first;
	b->first = new->next;
	if (!a->first)
	{
		a->first = new;
		a->last = new;
		new->next = NULL;
	}
	else
	{
		new->next = a->first;
		a->first = new;
	}
	ft_printf("pa\n");
}

void	ft_push_b(t_stack *b, t_stack *a)
{
	t_node *new;

	if (!a || !a->first)
		return ;
	new = a->first;
	a->first = new->next;
	if (!b->first)
	{
		b->first = new;
		b->last = new;
		new->next = NULL;
	}
	else
	{
		new->next = b->first;
		b->first = new;
	}
	ft_printf("pb\n");
}

void	ft_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !s->first)
		return ;
	node = s->first;
	s->first = s->first->next;
	s->last->next = node;
	s->last = node;
	node->next = NULL;
}

void	ft_rev_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !s->first)
		return ;
	node = s->first;
	while (node->next != s->last)
		node = node->next;
	node->next->next = s->first;
	s->first = node->next;
	node->next = NULL;
	s->last = node;
}
