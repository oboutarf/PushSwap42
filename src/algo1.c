/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/07 19:11:36 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

stack	*give_ra_rra(stack *sta)
{	
	int		size = get_stacklen(sta);
	int		orig_elem = 0;

	while (size > 0)
	{
		sta->ra = orig_elem;
		sta->rra = size;
		if (orig_elem == 0)
			sta->rra = orig_elem;
		sta = sta->next;
		orig_elem++;
		size--;
	}
	return (sta);
}

stack	*give_rb_rrb(stack *stb)
{	
	int		size = get_stacklen(stb);
	int		orig_elem = 0;

	while (size > 0)
	{
		stb->ra = orig_elem;
		stb->rra = size;
		if (orig_elem == 0)
			stb->rra = orig_elem;
		stb = stb->next;
		orig_elem++;
		size--;
	}
	return (stb);
}

void	search_elem_back_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{	
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value >= stb.value && last_a->value <= stb.value)
			break ;
		ft_rra(sta);
	}
}

void	search_elem_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{	
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value >= stb.value && last_a->value <= stb.value)
			break ;
		ft_ra(sta);
	}
}

void	choose_which_way_a(stack **sta, stack stb)
{
	stack *last_a;
	
	last_a = *sta;
	while (last_a->next)
		last_a = last_a->next;
	if (stb.value < last_a->value)
		search_elem_back_a(sta, stb);
	else
		search_elem_a(sta, stb);
}

void	what_move_a(stack *sta, stack *stb)
{
	// int		size = get_stacklen(stb) / 2;
	 
	while (stb)
	{
		choose_which_way_a(&sta, *stb);
		ft_pa(&sta, &stb);
		// size--;
	}
	// choose_which_way_a(&sta, *stb);
	// ft_pa(&sta, &stb);
}

void	maxmin(stack *sta, stack *stb)
{
	int		save_value;

	save_value = -1;
	while (stb->target_pos != 0)
	{
		ft_rrb(&stb);
		save_value++;
	}
	ft_pa(&sta, &stb);
	while (stb->target_pos != get_stacklen(stb))
	{
		ft_rb(&stb);
		save_value--;
	}
	ft_pa(&sta, &stb);
	printf("%i\n", save_value);
	if (save_value > 0)
		while ((save_value++ < 0))
			ft_rrb(&stb);
	else if (save_value > 0)
		while (save_value-- > 0)
			ft_rb(&stb);
	//what_move_a(sta, stb);
}

void	chunk_it(stack *sta, stack *stb, int size)
{
	int		*chunk;

	chunk = malloc(sizeof(int) * 10);
	chunk[0] = 0;
	if (size > 100)
		chunk[1] = size / 12;
	else
		chunk[1] = size / 3;
	chunk[2] = chunk[1];
	chunk[3] = chunk[1];
	chunk[4] = get_stacklen(sta);
	while (chunk[4] > 0)
	{
		chunk[2] = chunk[3];
		while (chunk[2] > 0)
		{
			if (!sta)
				break ;
			if (sta->target_pos >= chunk[0] && sta->target_pos < chunk[1])
			{
				ft_pb(&sta, &stb);
				chunk[2]--;
				chunk[4]--;
			}
			else
				ft_ra(&sta);
		}
		chunk[0] += chunk[3];
		chunk[1] += chunk[3];
	}
	maxmin(sta, stb);
}
