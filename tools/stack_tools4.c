/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:55:33 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 19:58:19 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

t_booln	fill_stack(t_stack **stack_a, int ac, char **av)
{
	while (ac > 0)
	{
		(*stack_a) = elem_addto_stack(stack_a, ft_atoi(av[ac]));
		if (!ft_isnumber(av[ac]))
			return (clear_stack(*stack_a), 0);
		if (!(*stack_a))
			return (clear_stack(*stack_a), 0);
		ac--;
	}
	return (1);
}

void	print_stack(t_stack *st)
{
	t_stack	*start;

	start = st;
	if (is_stack_clear(st) == clear)
	{
		printf("->   stack is clear, nothing to display!\n");
		return ;
	}
	while (is_stack_clear(st) == unclear)
		st = st->next;
	st = start;
	return ;
}

int	max_elem(t_stack **sta)
{
	t_stack	*start;
	int		max_elem;

	start = (*sta);
	max_elem = 0;
	max_elem = (*sta)->value;
	while ((*sta)->next != NULL)
	{
		if ((*sta)->value > max_elem)
			max_elem = (*sta)->value;
		(*sta) = (*sta)->next;
	}
	(*sta) = start;
	return (max_elem);
}

int	get_stacklen(t_stack *st)
{
	int		total_len;

	if (!st)
		return (0);
	total_len = 0;
	while (st)
	{
		st = st->next;
		total_len++;
	}
	return (total_len);
}
