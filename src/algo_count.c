/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:54:52 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/20 10:59:29 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	calc_final_cost(stack *sta, stack *stb, int sta_len, int stb_len)
{
	int	nb_r_b;
	int	nb_rr_b;
	int	nb_r_a;
	int	nb_rr_a;
	int	all_costs[4];
	int	i;

	i = 0;
	nb_r_b = stb->pos;
	nb_rr_b = stb_len - nb_r_b;
	nb_r_a = sta->pos;
	nb_rr_a = sta_len - nb_r_a;
	all_costs[0] = nb_r_a + nb_r_b;
	all_costs[1] = nb_r_a + nb_rr_b;
	all_costs[2] = nb_rr_a + nb_r_b;
	all_costs[3] = nb_rr_a + nb_rr_b;
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