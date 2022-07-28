/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:43:23 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/04 12:11:21 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_strdup() renvoie un pointeur sur une nouvelle chaîne de
** caractères qui est dupliquée depuis s1. La mémoire occupée par cette nouvelle
** chaîne est obtenue en appelant malloc.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = -1;
	while (s1[++i])
		;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}
