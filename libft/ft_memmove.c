/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:46 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/09 13:42:52 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** La fonction ft_memmove() permet de copier un bloc de mémoire 
** (possible chevauchement) spécifié par le paramètre src,
** et dont la taille est spécifiée via le paramètre len,
** dans un nouvel emplacement désigné par le paramètre dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*bufferdst;
	unsigned char	*buffersrc;
	size_t			i;

	bufferdst = (unsigned char *)dst;
	buffersrc = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (bufferdst > buffersrc)
	{
		while (++i <= len)
			bufferdst[len - i] = buffersrc[len - i];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
