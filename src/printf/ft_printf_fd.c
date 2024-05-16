/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:14:45 by avialle-          #+#    #+#             */
/*   Updated: 2024/05/16 13:41:09 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_char_fd(int fd, char c, size_t *len)
{
	write(fd, &c, 1);
	(*len)++;
}

void	print_str_fd(int fd, char *s, size_t *len)
{
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		print_char_fd(fd, s[i], len);
		i++;
	}
}

void	print_flag_fd(int fd, va_list args, char *str, size_t *len)
{
	if (str[0] == 'c')
		print_char_fd(fd, va_arg(args, int), len);
	else if (str[0] == 's')
		print_str_fd(fd, va_arg(args, char *), len);
	else if (str[0] == 'p')
		print_ptr_fd(fd, va_arg(args, void *), len);
	else if (str[0] == 'd' || str[0] == 'i')
		print_nbr_fd(fd, va_arg(args, int), len);
	else if (str[0] == 'u')
		print_unbr_fd(fd, va_arg(args, unsigned int), len);
	else if (str[0] == 'x')
		print_hexa_fd(fd, va_arg(args, unsigned int ), len, "0123456789abcdef");
	else if (str[0] == 'X')
		print_hexa_fd(fd, va_arg(args, unsigned int), len, "0123456789ABCDEF");
	else if (str[0] == '%')
		print_char_fd(fd, '%', len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	if (!str || fd < 0)
		return (-1);
	if (write(fd, 0, 0) == -1)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_flag_fd(fd, args, (char *)&str[i], &len);
		}
		else
			print_char_fd(fd, str[i], &len);
		i++;
	}
	va_end(args);
	return ((int)len);
}
