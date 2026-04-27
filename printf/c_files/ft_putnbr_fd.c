/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:52:34 by srosu            #+#    #+#              */
/*   Updated: 2026/04/24 15:55:38 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long long n, int fd, int *count)
{
	char				c;
	unsigned long long	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		++(*count);
		nb = -(unsigned long long) n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd, count);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	++(*count);
}
