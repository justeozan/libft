/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:55 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*gc_substr(char const *s, unsigned int start, size_t len, int gc_id)
{
	char	*dest;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		dest = (char *)gc_malloc(sizeof(char), gc_id);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (start + len > s_len)
		len = s_len - start;
	dest = (char *)gc_malloc((len + 1) * sizeof(char), gc_id);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &s[start], len);
	dest[len] = '\0';
	return (dest);
}
