/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:05:34 by mbuchet           #+#    #+#             */
/*   Updated: 2026/05/06 17:06:13 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	word_len(char const *s, int start, char c)
{
	int	wl;

	wl = 0;
	while (s[start + wl] != c && s[start + wl] != '\0')
		wl++;
	return (wl);
}
