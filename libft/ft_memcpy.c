/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:22:04 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/10 17:31:52 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_memcpy() permet de copier un bloc de mémoire 
** (sans chevauchement) spécifié par le paramètre src, et dont 
** la taille est spécifiée via le paramètre n, dans un nouvel 
** emplacement désigné par le paramètre dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*bufferdst;
	char	*buffersrc;

	bufferdst = (char *)dst;
	buffersrc = (char *)src;
	if (src == dst)
		return (dst);
	while (n--)
		*bufferdst++ = *buffersrc++;
	return (dst);
}
