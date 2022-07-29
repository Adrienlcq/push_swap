/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:35:30 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 12:58:39 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	debug(t_stack *a, t_stack *b)
{
	int	i = 1;
	printf("Liste A:\n");
	for (t_node *node = a->first; node != NULL; node = node->next)
	{
		printf("node %d : nb = %d\n", i, node->nb);
		i++;
	}
	i = 1;
	printf("\nList B:\n");
	for (t_node *node = b->first; node != NULL; node = node->next)
	{
		printf("node %d : nb = %d\n", i, node->nb);
		i++;
	}
}