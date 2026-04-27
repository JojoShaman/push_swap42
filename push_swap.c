/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: srosu <srosu@student.42belgium.be>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/21 14:10:15 by srosu            #+#    #+#              */
/*   Updated: 2026/04/27 18:42:43 by srosu           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*str_join(char *dst, const char *src)
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

int	main(int argc, char **argv)
{
	int		i;
	t_data	*stack;
	char	*str;
	char	*tmp;

	i = 1;
	str = NULL;
	tmp = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		stack = create_stack_a(argv[i]);
	else if (argc > 2)
	{
		while (i < argc)
		{
			tmp = str;
			str = str_join(tmp, argv[i]);
			if (tmp)
				free(tmp);
			if (i != argc - 1)
			{
				tmp = str;
				str = str_join(tmp, " ");
				free(tmp);
			}
			i++;
		}
		stack = create_stack_a(str);
	}
	if (str)
		free(str);
	// ft_printf("** stack a **\n");
	// print_stack(&stack->stack_a);
	tiny_sort(&stack->stack_a);
	// ft_printf("\n--------------------------\n\n");
	// ft_printf("** stack a **\n");
	// print_stack(&stack->stack_a);
	return (0);
}
