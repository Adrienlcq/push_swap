/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:24:16 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 13:03:10 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	print_error(char *str, int ret)
{
	ft_printf(str);
	return (ret);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_node	*tmp;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	a = ft_init_stack(a);
	b = ft_init_stack(b);
	if (a == NULL || b == NULL)
		return (1);
	i = 0;
	while (av[++i])
	{
		if ((ft_atol(av[i]) < MIN_INT || ft_atol(av[i]) > MAX_INT)
			|| check_arg(av[i]) == 1 || ft_strlen(av[i]) > 11 || ac < 2)
		{
			a = ft_delete_list(a);
			b = ft_delete_list(b);
			return (print_error("ERROR\n", 2));
		}
		else
		{
			tmp = a->first;
			while (tmp != NULL)
			{
				if (tmp->nb == ft_atol(av[i]))
				{
					a = ft_delete_list(a);
					b = ft_delete_list(b);
					return (print_error("ERROR\n", 2));
				}
				tmp = tmp->next;
			}
			if (ft_add_list(a, ft_atol(av[i])) == 0)
			{
				a = ft_delete_list(a);
				b = ft_delete_list(b);
				return (print_error("ERROR\n", 2));
			}
		}
	}
	ft_algo(a, b);
	a = ft_delete_list(a);
	b = ft_delete_list(b);
	return (0);
}
