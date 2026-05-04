/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   handler.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/08 17:06:23 by srosu            #+#    #+#              */
/*   Updated: 2026/05/05 00:49:46 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_ptr_string(char *s, int fd, int *count)
{
	if (s)
		ft_putstr_fd(s, fd, count);
	else
		ft_putstr_fd("(null)", fd, count);
}

static void	check_ptr_p(unsigned long p, int *count)
{
	if (p)
	{
		ft_putstr_fd("0x", 1, count);
		ft_putnbr_base(p, "0123456789abcdef", count);
	}
	else
	{
		ft_putstr_fd("0x", 1, count);
		ft_putchar_fd('0', 1, count);
	}
}

void	type_is(char c, va_list * ap, int *count)
{
	unsigned long	arg;

	if (c == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1, count);
	if (c == 's')
		check_ptr_string(va_arg(*ap, char *), 1, count);
	if (c == 'p')
		check_ptr_p((unsigned long) va_arg(*ap, void *), count);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd((long long) va_arg(*ap, int), 1, count);
	if (c == 'u' || c == 'x' || c == 'X')
	{
		arg = (unsigned long) va_arg(*ap, unsigned int);
		if (c == 'u')
			ft_putnbr_base(arg, "0123456789", count);
		if (c == 'x')
			ft_putnbr_base(arg, "0123456789abcdef", count);
		if (c == 'X')
			ft_putnbr_base(arg, "0123456789ABCDEF", count);
	}
	if (c == '%')
		ft_putchar_fd('%', 1, count);
}
