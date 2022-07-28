/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:45:51 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/04 11:54:32 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_memset() remplit les len premiers octets de la zone mémoire 
** pointée par b avec l'octet c. 
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (len > 0)
	{
		str[i] = c;
		i++;
		len--;
	}
	return ((void *)str);
}
