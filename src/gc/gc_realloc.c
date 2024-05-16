/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:26 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	max_value_size_t(size_t v1, size_t v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}

void	*gc_realloc(void *ptr, size_t old_size, size_t new_size, int gc_id)
{
	size_t	size;
	void	*new;

	if (new_size == 0)
		return (gc_del_one(ptr, gc_id), NULL);
	size = (size_t)max_value_size_t(old_size, new_size);
	new = gc_malloc(size, gc_id);
	if (ptr)
		ft_memcpy(new, ptr, size);
	gc_del_one(ptr, gc_id);
	return (new);
}
