/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:21:33 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 18:33:54 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

t_booln	is_stack_clear(t_stack *st)
{
	if (st == NULL)
		return (clear);
	return (unclear);
}

t_stack	*elem_addto_stack(t_stack **st, int x)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (!element)
	{
		printf("Malloc error !");
		return (NULL);
	}
	element->value = x;
	element->final_cost = -1;
	element->next = *st;
	*st = element;
	return (element);
}

t_stack	*clear_stack(t_stack *st)
{
	t_stack	*element;

	if (is_stack_clear(st) == clear)
		return (create_new_stack());
	element = st->next;
	free(st);
	return (clear_stack(element));
}

t_booln	ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_index(t_stack *st)
{
	int		index;

	index = 0;
	while (st)
	{
		st->pos = index++;
		st = st->next;
	}
}
