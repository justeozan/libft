/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:25:31 by ozasahin          #+#    #+#             */
/*   Updated: 2024/05/16 12:05:13 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// Function for free matrix without comments
void	ft_free_matrix(void **matrix, int height, void (*free_func)(void *))
{
	int	i;

	i = 0;
	if (!(*matrix) || !matrix)
		return ;
	while (i < height)
	{
		free_func(matrix[i++]);
	}
	free(matrix);
	matrix = NULL;
}

// Function for free matrix with comments
void	ft_free_matrix_(void **matrix, int height, void (*free_func)(void *))
{
	int	i;

	i = 0;
	ft_printf("--\nTry to free 2d structure:\n");
	while (i < height)
	{
		free_func(matrix[i++]);
		ft_printf("matrix[%d] = %s\n", i - 1, (char *)matrix[i]);
	}
	free(matrix);
	matrix = NULL;
	ft_printf("matrix = %s\n", (char **)matrix);
}

// fmxe = free matrix and error
void	ft_fmxe(void **matrix, int h, void (*f)(void *), char *err_txt)
{
	ft_free_matrix(matrix, h, f);
	exit_err(err_txt);
}

// With comments
void	ft_fmxe_(void **matrix, int h, void (*f)(void *), char *err_txt)
{
	ft_free_matrix_(matrix, h, f);
	exit_err(err_txt);
}
