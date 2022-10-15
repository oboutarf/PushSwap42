/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/15 18:34:53 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

////////////////////////////////////////////////////+   UPGRADED VERSION   +\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


int		Search_LowCost(stack *stb)
{
	int		f_cost = stb->final_cost;
	int		pos = 0;

	while (stb)
	{
		if (stb->final_cost < f_cost)
		{
			f_cost = stb->final_cost;
			pos = stb->pos;
		}
		stb = stb->next;
	}
	return (pos);
}


void	move_it(int	to_move, stack **sta, stack **stb)
{
	int	mediane_a = get_stacklen(*sta) / 2;
	int	mediane_b = get_stacklen(*stb) / 2;
	int	nb_rotate_a;
	int	nb_rotate_b;
	stack	*tmp;

	tmp = *stb;
	while (tmp->pos != to_move)
		tmp = tmp->next;
	nb_rotate_a = tmp->target_pos;
	nb_rotate_b = tmp->pos;
	while (nb_rotate_b--)
	{
		if (to_move < mediane_b)
			ft_rb(stb);
		else
			ft_rrb(stb);
	}
	while (nb_rotate_a--)
	{
		if (tmp->target_pos < mediane_a)
			ft_ra(sta);
		else
			ft_rra(sta);
	}
}


int		search_Prev(stack *sta)
{
	int		prev = 0;

	while (sta->next)
		sta = sta->next;
	prev = sta->final_index;
	return (prev);
}


int	final_Cost(stack *sta, stack *stb)
{
	stb->final_cost = sta->pos + stb->pos;
	return (stb->final_cost);
}


void	instruct_B(stack *sta, stack *stb)
{
	// int		prev = search_Prev(sta);
	stack	*sta_save = sta;
	int		cost = 1000;

	while (stb)
	{
		sta = sta_save;
		while (sta)
		{
			// write(1, "yoyo\n", 5);
			if (stb->final_index < sta->final_index)
			{
				if (final_Cost(sta, stb) < cost)
				{
					cost = final_Cost(sta, stb);
					stb->target_pos = sta->pos;
				}
			}
			else
			{
				// prev = sta->final_index;
				sta = sta->next;
			}
		}
		stb = stb->next;
	}
}

void	algo(stack **sta, stack **stb)
{
	int	node_to_move;	
	
	while (stb)
	{
		instruct_B(*sta, *stb);
		// write(1, "yoyo", 4);
		node_to_move = Search_LowCost(*stb);
		move_it(node_to_move, sta, stb);
		ft_pa(sta, stb);
		ft_index(*sta);
		ft_index(*stb);
	}
}


void	chunk_it(stack *sta, stack *stb, int size)
{
	int		*chunk;

	chunk = malloc(sizeof(int) * 10);
	chunk[0] = 0;
	if (size > 99)
		chunk[1] = size / 4;
	else
		chunk[1] = size / 2;
	chunk[2] = chunk[1];
	chunk[3] = chunk[1];
	chunk[4] = get_stacklen(sta) - 1;
	chunk[5] = chunk[4];
	while (chunk[4] > 2)
	{
		chunk[2] = chunk[3];
		while (chunk[2] > 0)
		{
			if (get_stacklen(sta) == 2)
				break ;
			if (sta->final_index >= chunk[0] && sta->final_index < chunk[1])
			{
				if (sta->final_index != 0 && sta->final_index != chunk[5])
				{
					ft_pb(&sta, &stb);
					chunk[2]--;
					chunk[4]--;
				}
				else
				{
					chunk[2]--;
					chunk[4]--;
					ft_ra(&sta);
				}
			}
			else
				ft_ra(&sta);
		}
		chunk[0] += chunk[3];
		chunk[1] += chunk[3];
	}
	ft_ra(&sta);
	ft_index(sta);
	ft_index(stb);
	algo(&sta, &stb);
}
