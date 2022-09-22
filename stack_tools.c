/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:21:33 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/21 16:44:50 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// $ // ----------------------------------------------------------------- // # //

stack   *create_new_stack(void)
{
    return (NULL);
}

// $ // ----------------------------------------------------------------- // # //

booln   is_stack_clear(stack *st)
{
    if (st == NULL)
        return (clear);
    return (unclear);
}

// $ // ----------------------------------------------------------------- // # //

int	ft_atoi(char *nptr)
{
	int		mns;
	int		num;
	int		i;

	i = 0;
	num = 0;
	mns = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		mns = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * mns);
}

// $ // ----------------------------------------------------------------- // # //

stack   *elem_addto_stack(stack **st, int x, int index)
{
    stack   *element;

    element = malloc(sizeof(*element));
    if (!element)
    {
        printf("Malloc error !");
        return (NULL);
    }
    element->value = x;
    element->index = index;
    element->cost = 0;
    element->next = *st;
    *st = element;
    return (element);
}

// $ // ----------------------------------------------------------------- // # //

// int     ft_index(stack **st, int value)
// int     fill_stack() 

// $ // ----------------------------------------------------------------- // # //

stack   *clear_stack(stack *st)
{
    stack   *element;
    
    if (is_stack_clear(st) == clear)
        return (create_new_stack());
    element = st->next;
    free(st);
    return (clear_stack(element));
}

// $ // ----------------------------------------------------------------- // # //

void    print_stack(stack *st)
{
    if (is_stack_clear(st) == clear)
    {
        printf("->      stack is clear, nothing to display !\n");
        return;
    }
    while (is_stack_clear(st) == unclear)
    {
        printf("value => %d, index => %d, cost => %d\n", st->value, st->index, st->cost);
        st = st->next;
    }
    return ;
}

// $ // ----------------------------------------------------------------- // # //