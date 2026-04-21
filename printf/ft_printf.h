/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <sorinrosu45@gmail.com>             #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:20:36 by srosu            #+#    #+#              */
/*   Updated: 2026/04/08 18:14:40 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	type_is(char c, va_list ap, int *count);
void	ft_putchar_fd(int c, int fd, int *count);
void	ft_putnbr_base(long nb, char *base, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count);
int		ft_printf(const char *format, ...);

#endif
