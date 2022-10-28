/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:04:30 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 16:49:15 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

t_stack	*create_new_stack(void)
{
	return (NULL);
}

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

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_booln	ft_isdup(char **av)
{
	int		i;
	int		j;
	
	i = 1;
	j = 0;
	while (av[j])
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			i++;
		}
		j++;
		i = j + 1;
		
	}
	return (0);
}

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
	{
		printf("   %d    INFOS --->  pos: %d   final__index: %d\n", st->value, st->pos, st->final_index);
		st = st->next;//---> Add printf to print
	}
	st = start;
	return ;
}
