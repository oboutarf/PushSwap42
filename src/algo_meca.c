/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_meca.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:57:21 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/20 11:00:16 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	move_it(int	to_move, stack **sta, stack **stb)
{
	int		nb_rotate_a;
	int		nb_rotate_b;
	stack	*stb_save;

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

void	put_staup(stack *sta)
{
	int		mid = get_stacklen(sta) / 2;

	if (sta->final_index < mid)
		while (sta->final_index != 0)
			ft_ra(&sta);
	else
		while (sta->final_index != 0)
			ft_rra(&sta);
	printf("\n\nStack A\n\n");
	print_stack(sta);
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
			
		node_to_move = Search_LowCost(*stb);
		
		move_it(node_to_move, sta, stb);
		
		ft_pa(sta, stb);

		ft_index(*sta);
		ft_index(*stb);
		reset_instruct_B(*stb);
	}
	reset_instruct_B(*sta);
	put_staup(*sta);
	// printf("\n\nStack A\n\n");
	// print_stack(*sta);
	// printf("\n\nStack B\n\n");
	// print_stack(*stb);
}