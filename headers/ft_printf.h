/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/07 15:20:36 by srosu            #+#    #+#              */
/*   Updated: 2026/04/24 15:53:01 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	type_is(char c, va_list *ap, int *count);
void	ft_putchar_fd(int c, int fd, int *count);
void	ft_putnbr_base(unsigned long nb, char *base, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(long long n, int fd, int *count);

#endif
