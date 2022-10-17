/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/17 19:04:25 by oboutarf         ###   ########.fr       */
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
		if (stb->final_cost < f_cost && stb->final_cost >= 0)
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
	int		nb_rotate_a;
	int		nb_rotate_b;
	stack	*stb_save;

	//	On cherche le maillon a bouger dans B
	stb_save = *stb;
	while (stb_save->pos != to_move)
		stb_save = stb_save->next;
	//	On recupere les positions (pos de A == nb de rotate a ; pos de B == nb de rotate b)
	nb_rotate_a = stb_save->next_pos;
	nb_rotate_b = stb_save->pos;
	//	On polarise le resultat ( negatif == reverse rotate ; positif == rotate)
	if (nb_rotate_a > get_stacklen(*sta) - nb_rotate_a)
	{
		nb_rotate_a = get_stacklen(*sta) - nb_rotate_a;
		nb_rotate_a *= -1;
	}
	if (nb_rotate_b > get_stacklen(*stb) - nb_rotate_b)
	{
		nb_rotate_b = get_stacklen(*stb) - nb_rotate_a;
		nb_rotate_b *= -1;
	}
	//	On teste le signe et on fait les mouvements
	if (nb_rotate_a > 0)
		while (nb_rotate_a--)
			ft_ra(sta);
	else
		while (nb_rotate_a++ != 0)
			ft_rra(sta);
	if (nb_rotate_b > 0)
		while (nb_rotate_b--)
			ft_rb(stb);
	else
		while (nb_rotate_b++ != 0)
			ft_rrb(stb);
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
//	printf("\nindex of prev: %i\n", index_of_previous_node);
	while (i++ < index_of_previous_node)
		sta = sta->next;
	value_of_previous_node = sta->value;
	return (value_of_previous_node);
}

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
			{
			//	printf("\n\nsta->pos: %i\nstb->pos: %i\n", sta->pos, stb->pos);
				calc_final_cost(sta, stb, get_stacklen(sta_save), get_stacklen(stb_save));
			}
			sta = sta->next;
		}
		stb = stb->next;
	}
}

void	reset_instruct_B(stack *stb)
{
	while (stb != NULL)
	{
		stb->final_cost = -1;
		stb->next_pos = 0;
		stb = stb->next;
	}
}

void	algo(stack **sta, stack **stb)
{
	int	node_to_move;
	
	while (*stb)
	{
		instruct_B(*sta, *stb);
		
		write(1, "\n\n\n\nA\n", 6);
		print_stack(*sta);
		write(1, "\n\n\n\nB\n", 6);
		print_stack(*stb);
		
		node_to_move = Search_LowCost(*stb);
		
		move_it(node_to_move, sta, stb);
		
		ft_pa(sta, stb);
		
		ft_index(*sta);
		ft_index(*stb);
		reset_instruct_B(*stb);
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
