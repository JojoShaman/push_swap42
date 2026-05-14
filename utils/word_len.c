/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   word_len.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 17:05:34 by srosu            #+#    #+#              */
/*   Updated: 2026/05/14 11:43:44 by srosu           ###   ########.fr        */
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
