/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_base.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 16:12:57 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 00:06:52 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putnbr_base(int fd, unsigned long nb, char *base, int *count)
{
	int		base_size;
	char	tab[20];
	int		i;

	base_size = 0;
	i = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd, count);
		return ;
	}
	while (base[base_size])
		base_size++;
	while (nb > 0)
	{
		tab[i] = base[nb % base_size];
		nb /= base_size;
		i++;
	}
	while (i != 0)
		ft_putchar_fd(tab[--i], fd, count);
}
