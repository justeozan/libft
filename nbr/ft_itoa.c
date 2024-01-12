/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:46:23 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/12 11:08:00 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	len_itoa(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	is_neg(int *sign, int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		(*sign)++;
	}
}

char	*ft_itoa(int n)
{
	char	*strn;
	int		sign;
	int		l;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	is_neg(&sign, &n);
	l = len_itoa(n);
	strn = ft_calloc((l + 1) + sign, 1);
	if (strn == NULL)
		return (NULL);
	if (sign == 0)
		l--;
	while (n > 0)
	{
		strn[l--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		strn[0] = '-';
	return (strn);
}
