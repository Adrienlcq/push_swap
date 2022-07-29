/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:58 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 15:15:20 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_or_rra(t_stack *a, t_stack *copy)
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
		if (copy == NULL)
			return ;
		ft_copy_list_min(a, copy);
		min = is_min(a);
		node = a->first;
		while (node->nb != min)
		{
			ft_ra_or_rra(a, copy);
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

	i = 0;
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

void	ft_choose_algo(t_stack *a, t_stack *b)
{
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
}

void	ft_algo(t_stack *a, t_stack *b)
{
	t_stack	*copy;

	copy = NULL;
	copy = ft_init_stack(copy);
	if (copy == NULL)
		return ;
	ft_copy_list(a, copy);
	copy = ft_sort_copy(copy);
	ft_rename_list(copy, a);
	ft_choose_algo(a, b);
	copy = ft_delete_list(copy);
}
