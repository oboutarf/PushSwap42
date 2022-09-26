/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:04:30 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/26 15:12:30 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

stack   *create_new_stack(void)
{ 
    return (NULL);
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

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

// $ // ----------------------------------------------------------------- // # //

booln   fill_stack(stack **stack_a, int ac, char **av)
{
    while (ac > 0)
    {
        (*stack_a) = elem_addto_stack(stack_a, ft_atoi(av[ac]), ac - 1);
        if (!ft_isnumber(av[ac]))
            return (clear_stack(*stack_a), 0);
        if (!(*stack_a))
            return (clear_stack(*stack_a), 0);
        ac--;
    }
    return (1);
}

// $ // ----------------------------------------------------------------- // # //

void    print_stack(stack *st)
{
    if (is_stack_clear(st) == clear)
    {
        printf("->   stack is clear, nothing to display!\n");
        return ;
    }
    while (is_stack_clear(st) == unclear)
    {
        printf("  %d    index: %d, target_pos: %d\n", st->value, st->index, st->target_pos);
        st = st->next;
    }
    return ;
}

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //