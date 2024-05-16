/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:20 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*gc_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *),
	int gc_id)
{
	t_list	*nlst;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		elem = gc_lstnew(f(lst->content), gc_id);
		if (!elem)
		{
			gc_clear(gc_id, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, elem);
		lst = lst->next;
	}
	return (nlst);
}
