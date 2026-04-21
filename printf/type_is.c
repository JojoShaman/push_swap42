/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   type_is.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <sorinrosu45@gmail.com>             #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/08 17:06:23 by srosu            #+#    #+#              */
/*   Updated: 2026/04/08 18:10:59 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_is(char c, va_list ap, int *count)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1, count);
	}
	if (c == 's')
	{
		ft_putstr_fd(va_arg(ap, char *), 1, count);
	}
	if (c == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base((long) va_arg(ap, void *), "0123456789abcdef", count);
	}
	if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(va_arg(ap, int), 1, count);
	}
	if (c == 'u')
	{
		ft_putnbr_unsigned_fd(va_arg(ap, int), 1, count);
	}
	if (c == 'x')
	{
		ft_putnbr_base((long) va_arg(ap, void *), "0123456789abcdef", count);
	} if (c == 'X')
	{
		ft_putnbr_base((long) va_arg(ap, void *), "0123456789ABCDEF", count);
	} if (c == '%')
	{
		ft_putchar_fd('%', 1, count);
	}
}
