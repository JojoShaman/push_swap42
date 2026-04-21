/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <sorinrosu45@gmail.com>             #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:52:34 by srosu            #+#    #+#              */
/*   Updated: 2026/04/08 18:20:43 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *count)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		++(*count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd, count);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
	++(*count);
}
