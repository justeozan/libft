/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:21 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*gc_lstnew(void *content, int gc_id)
{
	t_list	*element;

	element = (t_list *)gc_malloc(sizeof(t_list), gc_id);
	if (element == NULL)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
