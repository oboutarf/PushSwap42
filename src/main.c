/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/11 19:17:13 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int     main(int ac, char **av)
{
	stack	*stack_a;				
    stack   *stack_b;
    int     *size = malloc(sizeof(int)*10);
    
    stack_a = NULL;												
    stack_b = NULL;												

    if (ft_isdup(av))											
        return (write(2, "error\n", 6), 0);
    if (!(fill_stack(&stack_a, ac - 1, av)))
        return (write(2, "error\n", 6), 0);

    give_target(stack_a);
    size[0] = get_stacklen(stack_a);
    size[1] = size[0];
    chunk_it(stack_a, stack_b, size[0]);

    // maxmin(&stack_a, &stack_b, size[1]);
    // maxmin(&stack_a, &stack_b, size);
    // give_target(stack_a);
    // ob_radix(&stack_a, &stack_b, size[0]);
    // ft_div(&stack_a, &stack_b, size);

    return (1);
}
