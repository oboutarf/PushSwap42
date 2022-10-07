/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/07 11:55:41 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int     main(int ac, char **av)
{
	stack	*stack_a;				
    stack   *stack_b;
    int size = 0;
    
    stack_a = NULL;												
    stack_b = NULL;												

    if (ft_isdup(av))											
        return (write(2, "error\n", 6), 0);
    if (!(fill_stack(&stack_a, ac - 1, av)))
        return (write(2, "error\n", 6), 0);

    give_target(stack_a);
    size = get_stacklen(stack_a);
    chunk_it(stack_a, stack_b, size);
    give_target(stack_a);
    // ob_radix(&stack_a, &stack_b, size);
    // ft_div(&stack_a, &stack_b, size);
    
   /*printf(" 0000000000000000000000000000000000000000\n\n");
    printf("000000000000000   E N D   0000000000000000\n\n");
    printf(" 0000000000000000000000000000000000000000\n\n");*/
    return (1);
}
