/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/29 23:28:32 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (ft_isdup(av) < 0)
		return (write(2, "error\n", 6), 1);
	if (check_sorted(av, ac - 1) < 0)
		return (1);
	if (!(fill_stack(&stack_a, ac - 1, av)))
		return (write(2, "error\n", 6), 1);
	if (get_stacklen(stack_a) == 1)
		return (free_stacks(&stack_a, &stack_b), 1);
	size = get_stacklen(stack_a);
	give_target(stack_a);
	if (size == 3)
		stack_a = center_forthree(stack_a);
	else if (size == 5)
		stack_a = center_forfive(&stack_a, &stack_b);
	else if (size >= 1)
		stack_a = start_process(stack_a, stack_b, size);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
