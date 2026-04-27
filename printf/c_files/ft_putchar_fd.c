/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putchar_fd.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:28:12 by srosu            #+#    #+#              */
/*   Updated: 2026/04/24 15:40:34 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(int c, int fd, int *count)
{
	unsigned char	a;

	a = (unsigned char) c;
	write(fd, &a, 1);
	++(*count);
}
