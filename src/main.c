/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/01 16:23:22 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// $ // ----------------------------------------------------------------- // # //
//	Prototype main avec les arguments
// $ // ----------------------------------------------------------------- // # //

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

int     main(int ac, char **av)
{
	stack	*stack_a;
	int		i = 0;

	stack_a = create_new_stack();
	print_stack(stack_a);
	printf("# ---------------------------------- #\n");
	while (i < ac)
	{
		stack_a = elem_addto_stack(stack_a, ft_atoi(av[i]));
		//print_stack(stack_a);
		i++;
	}
	print_stack(stack_a);
	clear_stack(stack_a);
	printf("# ---------------------------------- #\n");
/* 	print_stack(stack_a); */
    return (1);
}

// $ // ----------------------------------------------------------------- // # //
//	Prototype main sans les arguments
// $ // ----------------------------------------------------------------- // # //


/*     printf("----------------------------\n");

    stack  *stack;
    //stack  stack_b;
    stack = create_new_stack();
    print_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    stack = elem_addto_stack(stack, 5);
    stack = elem_addto_stack(stack, 10);
      stack = elem_addto_stack(stack, 15);
    stack = elem_addto_stack(stack, 1110);
    printf("----------------------------\n");
    print_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    printf("----------------------------\n");
    stack = clear_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    print_stack(stack); */
    
// $ // ----------------------------------------------------------------- // # //
 