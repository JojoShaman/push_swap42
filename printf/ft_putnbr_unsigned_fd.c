/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_unsigned_fd.c                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <sorinrosu45@gmail.com>             #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/08 16:59:26 by srosu            #+#    #+#              */
/*   Updated: 2026/04/08 18:21:03 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_unsigned_fd((n / 10), fd, count);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
	++(*count);
}
