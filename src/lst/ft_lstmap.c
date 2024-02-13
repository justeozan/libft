/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:30:28 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/13 16:57:15 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_block;
	void	*temp;

	new_lst = NULL;
	tmp_block = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp_block = ft_lstnew(temp);
		if (!tmp_block)
		{
			ft_lstclear(&new_lst, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_block);
		lst = lst->next;
	}
	return (new_lst);
}
