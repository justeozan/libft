/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:20:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/12 11:00:26 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	ls2;
	size_t	i;
	size_t	j;

	ls2 = ft_strlen(s2);
	if (ls2 == 0)
		return ((char *)s1);
	j = 0;
	while (s1[j] && j < len)
	{
		i = 0;
		while (s1[j + i] == s2[i] && s1[j + i] && i < ls2 && j + i < len)
			i++;
		if (i == ls2)
			return ((char *)&s1[j]);
		j++;
	}
	return (NULL);
}
