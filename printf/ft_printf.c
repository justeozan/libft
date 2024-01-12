/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:08:29 by justo             #+#    #+#             */
/*   Updated: 2024/01/12 11:05:27 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_char(int c, size_t *octet)
{
	write(1, &c, 1);
	(*octet)++;
}

void	print_var(char offset, va_list arg, size_t *octet)
{
	if (offset == 'c')
		ft_print_char(va_arg(arg, int), octet);
	else if (offset == 's')
		ft_print_str(va_arg(arg, char *), octet);
	else if (offset == 'p')
		ft_print_ptr(va_arg(arg, unsigned long long), octet);
	else if (offset == 'd')
		ft_print_nbr(va_arg(arg, int), octet);
	else if (offset == 'i')
		ft_print_nbr(va_arg(arg, int), octet);
	else if (offset == 'u')
		ft_print_unbr(va_arg(arg, unsigned int), octet);
	else if (offset == 'x')
		ft_print_hexa(va_arg(arg, unsigned int), "0123456789abcdef", octet);
	else if (offset == 'X')
		ft_print_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF", octet);
	else if (offset == '%')
		ft_print_char('%', octet);
}

int	ft_printf(const char *entry, ...)
{
	size_t		i;
	size_t		len;
	va_list		args;

	i = 0;
	va_start(args, entry);
	len = 0;
	while (entry[i])
	{
		if (entry[i] == '%')
		{
			print_var(entry[i + 1], args, &len);
			i++;
		}
		else
			ft_print_char(entry[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
