/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:27:48 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/10 19:06:39 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_strrchr() renvoie un pointeur sur la dernière occurrence
** du caractère c dans la chaîne s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	j;

	j = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == j)
		return (str + i);
	while (i >= 0)
	{
		if (str[i] == j)
			return (str + i);
		i--;
	}
	return (NULL);
}
