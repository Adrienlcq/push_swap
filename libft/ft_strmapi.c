/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:00:10 by adlecler          #+#    #+#             */
/*   Updated: 2021/12/04 12:21:27 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction ’f’ à chaque caractère de la
** chaine de caractères passée en argument pour créer
** une nouvelle chaine de caractères (avec malloc)
** résultant des applications successives de ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
