/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:22:07 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/13 11:25:19 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_strchr() renvoie un pointeur sur la première occurrence
** du caractère c dans la chaîne s.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	j;

	j = (char)c;
	str = (char *)s;
	while (*str && *str != j)
		str++;
	if (*str == j)
		return (str);
	return (0);
}
