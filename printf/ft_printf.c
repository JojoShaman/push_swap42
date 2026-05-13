/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:21:04 by srosu            #+#    #+#              */
/*   Updated: 2026/05/07 00:08:17 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	int			i;
	int			count;
	va_list		ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], fd, &count);
			i++;
		}
		else
		{
			type_is(fd, format[++i], &ap, &count);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
