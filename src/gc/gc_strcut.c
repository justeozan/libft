/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:28 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*gc_strcut(char const *str, size_t cut_begin, size_t cut_end, int gc_id)
{
	char	*dest;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - cut_begin - cut_end;
	if (len <= 0)
		return (gc_strdup("", gc_id));
	dest = (char *)gc_calloc((len + 1), sizeof(char), gc_id);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &str[cut_begin], len + 1);
	dest[len] = 0;
	return (dest);
}
