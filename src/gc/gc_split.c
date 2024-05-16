/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:12:27 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	free_subs(char	**strs, size_t nb_subs, int gc_id)
{
	size_t	i;

	i = 0;
	while (i < nb_subs)
	{
		gc_del_one(strs, gc_id);
		strs[i] = NULL;
		i++;
	}
}

static int	count_subchain(char *s, char c)
{
	unsigned int	count;
	size_t			i;
	int				is_separator;

	is_separator = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && is_separator)
			count++;
		is_separator = (c == s[i]);
		i++;
	}
	return (count);
}

static char	*create_subchain(char *s, char c, int gc_id)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	str = NULL;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)gc_malloc((len + 1) * sizeof(char), gc_id);
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	create_strs(char const *s, char **strs, char c, int gc_id)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			strs[j] = create_subchain((char *)&s[i], c, gc_id);
			if (strs[j] == NULL)
			{
				free_subs(strs, j, gc_id);
				return (0);
			}
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	strs[j] = NULL;
	return (1);
}

char	**gc_split(char const *s, char c, int gc_id)
{
	char	**strs;
	size_t	len_subchain;

	if (s == NULL)
		return (NULL);
	len_subchain = count_subchain((char *)s, c);
	strs = (char **)gc_malloc((len_subchain + 1) * sizeof(char *), gc_id);
	if (!strs)
		return (NULL);
	if (!create_strs(s, strs, c, gc_id))
		return (gc_del_one(strs, gc_id), NULL);
	return (strs);
}
