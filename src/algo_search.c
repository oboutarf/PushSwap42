/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:02:37 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/24 12:23:41 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int		Search_LowCost(stack *stb)
{
	int		f_cost = stb->final_cost;
	int		pos = 0;

	while (stb)
	{
		if (stb->final_cost < f_cost && stb->final_cost >= 0)
		{
			f_cost = stb->final_cost;
			pos = stb->pos;
		}
		stb = stb->next;
	}
	return (pos);
}


int		search_Prev(stack *sta, int index_of_current_node)
{
	int	i;
	int	index_of_previous_node;
	int	value_of_previous_node;

	i = 0;
	if (index_of_current_node == 0)
		index_of_previous_node = get_stacklen(sta) - 1;
	else
		index_of_previous_node = index_of_current_node - 1;
	while (i++ < index_of_previous_node)
		sta = sta->next;
	value_of_previous_node = sta->value;
	return (value_of_previous_node);
}

void	instruct_B(stack *sta, stack *stb)
{
	stack	*sta_save = sta;
	stack	*stb_save = stb;
	int		prev = 0;

	while (stb)
	{
		sta = sta_save;
		while (sta)
		{
			prev = search_Prev(sta_save, sta->pos);
			if (stb->value < sta->value && prev < stb->value)
				calc_final_cost(sta, stb, get_stacklen(sta_save), get_stacklen(stb_save));
			sta = sta->next;
		}
		stb = stb->next;
	}
}

