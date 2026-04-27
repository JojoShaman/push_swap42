/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/27 21:25:40 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 21:25:42 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *dst, const char *src)
{
	char	*copy;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dst)
		dst = "";
	if (!src)
		src = "";
	copy = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(*copy));
	if (!copy)
		return (NULL);
	ptr = copy;
	while (dst[i])
	{
		copy[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		copy[i + j] = src[j];
		j++;
	}
	copy[i + j] = '\0';
	return (ptr);
}
