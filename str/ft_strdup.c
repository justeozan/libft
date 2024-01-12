/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:07:49 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/12 11:07:13 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	l;

	l = ft_strlen(str);
	result = (char *)malloc((l + 1) * sizeof(char));
	if (!result)
		return (NULL);
	l = 0;
	while (str[l] != '\0')
	{
		result[l] = str[l];
		l++;
	}
	result[l] = '\0';
	return (result);
}
