/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:55:07 by srosu             #+#    #+#             */
/*   Updated: 2026/05/15 03:05:25 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}

int	error_with_free_str(int fd, char *str)
{
	if (str != NULL)
	{
		str = NULL;
		free(str);
	}
	return (error(fd));
}
