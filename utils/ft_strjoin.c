/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 21:25:40 by srosu            #+#    #+#              */
/*   Updated: 2026/05/06 12:25:20 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	*ft_strjoin(char *dst, const char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dst)
		dst = "";
	if (!src)
		src = "";
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (dst[i])
	{
		str[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		str[i + j] = src[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
