/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:58 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 13:04:36 by adlecler         ###   ########.fr       */
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
		ft_add_list(copy, node->nb);
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
		ft_add_list(copy, node->nb);
		if (node->nb == min)
			break ;
		node = node->next;
	}
}

void	ft_algo_5(t_stack *a, t_stack *b)
{
	t_stack	*copy;
	int		min;
	t_node	*node;

	copy = NULL;
	while (ft_strlen_list(a) > 3)
	{
		copy = ft_init_stack(copy);
		ft_copy_list_min(a, copy);
		min = is_min(a);
		node = a->first;
		while (node->nb != min)
		{
			if (ft_strlen_list(copy) > 3)
			{
				ft_rev_rotate(a);
				ft_printf("rra\n");
			}
			else
			{
				ft_rotate(a);
				ft_printf("ra\n");
			}
			node = a->first;
		}
		ft_push_b(b, a);
		copy = ft_delete_list(copy);
	}
	ft_algo_3(a);
	while (ft_strlen_list(b) > 0)
		ft_push_a(a, b);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	nbr;
	int	i;
	int	j;
	int	size;

	(void)b;
	size = ft_strlen_list(a);
	while (!ft_is_sorted(a))
	{
		j = -1;
		while (++j < size)
		{
			nbr = a->first->nb;
			if ((nbr >> i) & 1)
			{
				ft_rotate(a);
				ft_printf("ra\n");
			}
			else
				ft_push_b(b, a);
		}
		while (ft_strlen_list(b) > 0)
			ft_push_a(a, b);
		i++;
	}
}

/* Fonction qui va selectionner quel algo doit-etre utilise */
void	ft_algo(t_stack *a, t_stack *b)
{
	t_stack	*copy;

	copy = NULL;
	copy = ft_init_stack(copy);
	ft_copy_list(a, copy);
	copy = ft_sort_copy(copy);
	ft_rename_list(copy, a);
	if (ft_is_sorted(a) == 1)
		return ;
	else if (ft_strlen_list(a) == 2)
	{
		ft_swap(a);
		ft_printf("sa\n");
		return ;
	}
	else if (ft_strlen_list(a) == 3)
	{
		ft_algo_3(a);
		return ;
	}
	else if (ft_strlen_list(a) == 5)
	{
		ft_algo_5(a, b);
		return ;
	}
	else
		ft_radix_sort(a, b);
	copy = ft_delete_list(copy);
}
