/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_del_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:16 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	gc_del_one(void *ptr_to_free, int gc_id)
{
	t_list	**alst;
	t_list	*tmp;
	t_list	*prev_element;

	alst = gc_ptr(gc_id);
	tmp = *alst;
	if (tmp && tmp->content == ptr_to_free)
	{
		*alst = tmp->next;
		ft_lstdelone(tmp, free);
		tmp = NULL;
	}
	while (tmp && tmp->content != ptr_to_free)
	{
		prev_element = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->content == ptr_to_free)
	{
		prev_element->next = tmp->next;
		ft_lstdelone(tmp, free);
		tmp = NULL;
	}
}
