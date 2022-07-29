/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:24:16 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 14:58:39 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_doublon_and_add_to_list(char *str, t_stack *a,
	t_stack *b)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp != NULL)
	{
		if (tmp->nb == ft_atol(str))
		{
			a = ft_delete_list(a);
			b = ft_delete_list(b);
			return (print_error("ERROR\n", 1));
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_parse_numbers(char **av, int ac, t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if ((ft_atol(av[i]) < MIN_INT || ft_atol(av[i]) > MAX_INT)
			|| check_arg(av[i]) == 1 || ft_strlen(av[i]) > 11 || ac < 2)
		{
			a = ft_delete_list(a);
			b = ft_delete_list(b);
			return (print_error("ERROR\n", 1));
		}
		else
		{
			if (ft_check_doublon_and_add_to_list(av[i], a, b) == 1)
				return (1);
			if (ft_add_list(a, ft_atol(av[i])) == 0)
			{
				a = ft_delete_list(a);
				b = ft_delete_list(b);
				return (print_error("ERROR\n", 1));
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	a = ft_init_stack(a);
	b = ft_init_stack(b);
	if (a == NULL || b == NULL)
		return (1);
	if (ft_parse_numbers(av, ac, a, b) == 1)
		return (1);
	ft_algo(a, b);
	a = ft_delete_list(a);
	b = ft_delete_list(b);
	return (0);
}
