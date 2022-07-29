/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:12:57 by adlecler          #+#    #+#             */
/*   Updated: 2022/07/29 12:53:20 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
}				t_stack;

t_stack		*ft_init_stack(t_stack *stack);
t_stack		*ft_delete_list(t_stack *stack);
int			check_arg(char *s);
int			print_error(char *str, int ret);
int			ft_add_list(t_stack *a, int nbr);
int			ft_strlen_list(t_stack *s);
int			is_min(t_stack *s);
int			ft_is_sorted(t_stack *stack);
long		ft_atol(const char *str);
void		ft_algo(t_stack *a, t_stack *b);
void		ft_algo_3(t_stack *a);
void		ft_copy_list_min(t_stack *a, t_stack *copy);

void		ft_push_a(t_stack *a, t_stack *b);
void		ft_push_b(t_stack *b, t_stack *a);
void		ft_swap(t_stack *s);
void		ft_rotate(t_stack *s);
void		ft_rev_rotate(t_stack *s);

/* DEBUG */
void		debug(t_stack *a, t_stack *b);

#endif