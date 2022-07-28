/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:56:44 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/04 12:16:40 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** La fonction ft_strjoin() concatène les string s1 et s2 dans une nouvelle
** string str. La mémoire occupée par cette nouvelle
** chaîne est obtenue en appelant malloc.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len_s1;
	int		len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len_s1] = s2[i];
			len_s1++;
		}
		str[len_s1] = '\0';
		return (str);
	}
	return (NULL);
}
