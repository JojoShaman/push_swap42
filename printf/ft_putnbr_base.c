/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_base.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <sorinrosu45@gmail.com>             #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 16:12:57 by srosu            #+#    #+#              */
/*   Updated: 2026/04/08 18:13:45 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long nb, char *base, int *count)
{
	int		base_size;
	char	tab[20];
	int		i;

	base_size = 0;
	i = 0;
	while (base[base_size])
	{
		base_size++;
	}
	while (nb > 0)
	{
		tab[i] = base[nb % base_size];
		nb /= base_size;
		i++;
	}
	while (i != 0)
	{
		ft_putchar_fd(tab[i - 1], 1, count);
		i--;
	}
}
