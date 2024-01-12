/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:11:52 by justo             #+#    #+#             */
/*   Updated: 2024/01/12 10:59:44 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_str(char *s, size_t *octet)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_print_char(s[i], octet);
		i++;
	}
}

void	ft_print_ptr(unsigned long long addr, size_t *octet)
{
	char	stack[17];
	int		i;

	if (!addr)
	{
		ft_print_str("(nil)", octet);
		return ;
	}
	i = 0;
	while (i < 16)
	{
		stack[i] = "0123456789abcdef"[addr % 16];
		i++;
		addr /= 16;
	}
	stack[i] = '\0';
	i = 15;
	while (stack[i] == '0')
		i--;
	ft_print_str("0x", octet);
	while (i >= 0)
	{
		ft_print_char(stack[i], octet);
		i--;
	}
}

void	ft_print_nbr(int nb, size_t *octet)
{
	if (nb == -2147483648)
		ft_print_str("-2147483648", octet);
	else if (nb < 0)
	{
		ft_print_char('-', octet);
		ft_print_nbr(-nb, octet);
	}
	else if (nb >= 10)
	{
		ft_print_nbr(nb / 10, octet);
		ft_print_nbr(nb % 10, octet);
	}
	else
		ft_print_char(nb + 48, octet);
}

void	ft_print_unbr(unsigned int nb, size_t *octet)
{
	if (nb >= 10)
	{
		ft_print_unbr(nb / 10, octet);
		ft_print_unbr(nb % 10, octet);
	}
	else
		ft_print_char(nb + 48, octet);
}

void	ft_print_hexa(unsigned int nb, char *base, size_t	*octet)
{
	if (nb > 15)
		ft_print_hexa(nb / 16, base, octet);
	ft_print_char(base[nb % 16], octet);
}
