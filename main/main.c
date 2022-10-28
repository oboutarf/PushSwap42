/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 18:30:25 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int	main(int ac, char **av)
{
	int		*size;
	t_stack	*stack_a;				
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	size = malloc(sizeof(int) * 10);
	if (ft_isdup(av))
		return (write(2, "error\n", 6), 0);
	if (!(fill_stack(&stack_a, ac - 1, av)))
		return (write(2, "error\n", 6), 0);
	size[0] = get_stacklen(stack_a);
	size[1] = size[0];
	give_target(stack_a);
	if (size[0] >= 7)
		start_process(stack_a, stack_b, size[0]);
	else if (size[0] == 3)
		center_forthree(stack_a);
	else if (size[0] == 5)
		center_forfive(&stack_a, &stack_b);
	return (1);
}
