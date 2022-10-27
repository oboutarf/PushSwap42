/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:54:52 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/27 11:18:26 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	calc_final_cost(stack *sta, stack *stb, int sta_len, int stb_len)
{
	int	all_costs[4];
	int	move_a[2];
	int	move_b[2];

	move_b[0] = stb->pos;
	move_b[1] = stb_len - move_b[0];
	move_a[0] = sta->pos;
	move_a[1] = sta_len - move_a[0];
	all_costs[0] = move_a[0] + move_b[0];
	all_costs[1] = move_a[0] + move_b[1];
	all_costs[2] = move_a[1] + move_b[0];
	all_costs[3] = move_a[1] + move_b[1];
	choose_best_cost(sta, stb, all_costs);
}

void	choose_best_cost(stack *sta, stack *stb, int *all_costs)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (all_costs[i] < all_costs[0])
			all_costs[0] = all_costs[i];
		i++;
	}
	if (stb->final_cost < 0 || stb->final_cost < all_costs[0])
	{
		stb->final_cost = all_costs[0];
		stb->next_pos = sta->pos;
	}
}
