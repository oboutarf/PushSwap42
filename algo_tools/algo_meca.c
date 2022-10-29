/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_meca.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:57:21 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/29 21:29:43 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	time_to_move(t_stack **sta, t_stack **stb, int rotate_a, int rotate_b)
{
	if (rotate_a > 0)
		while (rotate_a--)
			ft_ra(sta);
	else
		while (rotate_a++ != 0)
			ft_rra(sta);
	if (rotate_b > 0)
		while (rotate_b--)
			ft_rb(stb);
	else
		while (rotate_b++ != 0)
			ft_rrb(stb);
}

void	move_it(int to_move, t_stack **sta, t_stack **stb)
{
	int		nb_rotate_a;
	int		nb_rotate_b;
	t_stack	*stb_save;

	stb_save = *stb;
	while (stb_save->pos != to_move)
		stb_save = stb_save->next;
	nb_rotate_a = stb_save->next_pos;
	nb_rotate_b = stb_save->pos;
	if (nb_rotate_a > get_stacklen(*sta) - nb_rotate_a)
	{
		nb_rotate_a = get_stacklen(*sta) - nb_rotate_a;
		nb_rotate_a *= -1;
	}
	if (nb_rotate_b > get_stacklen(*stb) - nb_rotate_b)
	{
		nb_rotate_b = get_stacklen(*stb) - nb_rotate_b;
		nb_rotate_b *= -1;
	}
	time_to_move(sta, stb, nb_rotate_a, nb_rotate_b);
}

t_stack	*put_staup(t_stack *sta)
{
	int		mid;

	mid = get_stacklen(sta) / 2;
	if (sta->final_index > mid)
		while (sta->final_index != 0)
			ft_ra(&sta);
	else
		while (sta->final_index != 0)
			ft_rra(&sta);
	return (sta);
}

void	reset_instruct_b(t_stack *stb)
{
	while (stb != NULL)
	{
		stb->final_cost = -1;
		stb->next_pos = 0;
		stb = stb->next;
	}
}

t_stack	*algo(t_stack **sta, t_stack **stb)
{
	int	node_to_move;

	while (*stb)
	{
		instruct_b(*sta, *stb);
		node_to_move = search_lowcost(*stb);
		move_it(node_to_move, sta, stb);
		ft_pa(sta, stb);
		ft_index(*sta);
		ft_index(*stb);
		reset_instruct_b(*stb);
	}
	reset_instruct_b(*sta);
	give_target(*sta);
	*sta = put_staup(*sta);
	return (*sta);
}
