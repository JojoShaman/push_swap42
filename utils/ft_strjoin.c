/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:25:40 by srosu             #+#    #+#             */
/*   Updated: 2026/05/06 04:30:18 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
