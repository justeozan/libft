/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:51:00 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/13 16:23:36 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// coder une fonction qui permet de lire les resultats de la norm et 
// n'afficher que les KO, et sinon ecrire "Norm OK!"

// void	norm_is_not_ok(char **line)
// {
// 	ft_putstr_fd(*line, 2);
// 	free(line);
// 	line = NULL;
// }

// int	main(void)
// {
// 	char	*line;

// 	line = get_next_line(0);
// 	while (line != NULL)
// 	{
// 		if (ft_strnstr(line, "Error", ft_strlen(line)) == NULL)
// 			norm_is_not_ok(&line);
// 		free(line);
// 		line = get_next_line(0);
// 	}
// 	free(line);
// 	line = NULL;
// 	ft_putstr_fd("Norm is OK!", 2);
// 	return (0);
// }
