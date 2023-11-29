/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:15:03 by ozasahin          #+#    #+#             */
/*   Updated: 2023/11/17 09:15:03 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	l;
	size_t	i;
	char	*str;

	l = ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[l] = 0;
	i = -1;
	while (++i < l)
		str[i] = (*f)(i, s[i]);
	return (str);
}
