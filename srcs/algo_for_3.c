/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:57:52 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 12:55:23 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	sort_biggest_in_middle(t_stack *a)
{	
	if (a->first->nb < a->first->next->next->nb)
	{
		ft_printf("rra\n");
		ft_rev_rotate(a);
		ft_printf("sa\n");
		ft_swap(a);
	}
	else
	{
		ft_printf("rra\n");
		ft_rev_rotate(a);
	}
}

void	ft_algo_3(t_stack *a)
{
	if (a->first->nb > a->first->next->nb
		&& a->first->next->nb > a->first->next->next->nb)
	{
		ft_printf("sa\n");
		ft_swap(a);
		ft_printf("rra\n");
		ft_rev_rotate(a);
	}
	else if (a->first->nb > a->first->next->nb
		&& a->first->next->nb < a->first->next->next->nb)
	{
		if (a->first->nb > a->first->next->next->nb)
		{
			ft_printf("ra\n");
			ft_rotate(a);
		}
		else
		{
			ft_printf("sa\n");
			ft_swap(a);
		}
	}
	else if (a->first->nb < a->first->next->nb
		&& a->first->next->nb > a->first->next->next->nb)
		sort_biggest_in_middle(a);
}
