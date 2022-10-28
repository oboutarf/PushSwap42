/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:26:14 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 19:58:09 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int	ft_numlen(int n)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	give_target(t_stack *sta)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		idx;

	tmp = sta;
	while (tmp)
	{
		tmp2 = sta;
		idx = 0;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				idx++;
			tmp2 = tmp2->next;
		}
		tmp->final_index = idx;
		tmp = tmp->next;
	}
}

int	min_elem(t_stack **sta)
{
	t_stack	*start;
	int		min_elem;

	start = (*sta);
	min_elem = 0;
	min_elem = (*sta)->value;
	while ((*sta)->next != NULL)
	{
		if ((*sta)->value < min_elem)
			min_elem = (*sta)->value;
		(*sta) = (*sta)->next;
	}
	(*sta) = start;
	return (min_elem);
}
