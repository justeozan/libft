/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:14:35 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_ptr_fd(int fd, void *ptr, size_t *len)
{
	unsigned long	addr;
	char			addr_str[16];
	int				i;

	if (!ptr)
	{
		print_str_fd(fd, "(nil)", len);
		return ;
	}
	addr = (unsigned long)ptr;
	print_str_fd(fd, "0x", len);
	i = 0;
	while (addr)
	{
		addr_str[i++] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
	}
	while (i > 0)
		print_char_fd(fd, addr_str[--i], len);
}

void	print_hexa_fd(int fd, unsigned int nbr, size_t *len, char *base)
{
	if (nbr > 15)
		print_hexa_fd(fd, nbr / 16, len, base);
	print_char_fd(fd, base[nbr % 16], len);
}

void	print_nbr_fd(int fd, int nbr, size_t *len)
{
	if (nbr == -2147483648)
	{
		print_str_fd(fd, "-2147483648", len);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		print_char_fd(fd, '-', len);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		print_char_fd(fd, nbr + 48, len);
	}
	else
	{
		print_nbr_fd(fd, nbr / 10, len);
		print_nbr_fd(fd, nbr % 10, len);
	}
}

void	print_unbr_fd(int fd, unsigned int nbr, size_t *len)
{
	if (nbr > 9)
	{
		print_unbr_fd(fd, nbr / 10, len);
		print_unbr_fd(fd, nbr % 10, len);
	}
	else
		print_char_fd(fd, nbr + 48, len);
}
