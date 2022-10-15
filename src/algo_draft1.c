/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draft1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/15 14:54:01 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../incld/push_swap.h"
 
void	give_ra_rra(stack *sta)
{
	int		size[2];

	size[0] = get_stacklen(sta);
	size[1] = 0;
	while (size[0])
	{
		sta->ra = size[1];
		sta->rra = size[0]--;
		if (size[1] == 0)
			sta->rra = 0;
		sta = sta->next;
		size[1]++;
	}
}

void	give_rb_rrb(stack *stb)
{
	int		size[3];

	size[0] = get_stacklen(stb);
	size[1] = 0;
	while (size[0])
	{				printf("1st step A\n\n");
				print_stack(sta);

void	search_elem_back_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{
		give_ra_rra((*sta));
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value > stb.value && last_a->value < stb.value)
			break ;
		ft_rra(sta);
	}
}

void	search_elem_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{
		give_ra_rra((*sta));
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value > stb.value && last_a->value < stb.value)
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
	while (stb)
	{
		choose_which_way_a(&sta, *stb);
		// printf("\nPILEA\n\n");
		// print_stack(sta);
		// printf("\nPILEB\n\n");
		// print_stack(stb);
		// printf("\n");
		ft_pa(&sta, &stb);
	}
}

int		get_origlen(stack *sta, stack *stb)
{
	int		i[2];

	while (sta && i[0]++)
		sta = sta->next;
	while (stb && i[1]++)
		stb = stb->next;
	i[0] += i[1]; 
	return (i[0]);
}

void	chunk_it(stack *sta, stack *stb, int size)
{
	int		*chunk;

	chunk = malloc(sizeof(int) * 10);
	chunk[0] = 0;
	if (size > 99)
		chunk[1] = size / 12;
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
	what_move_a(sta, stb);
	return ;
} */


/* void	give_ra_rra(stack *sta)
{
	int		size[2];

	size[0] = get_stacklen(sta);
	size[1] = 0;
	while (size[0])
	{
		sta->ra = size[1];
		sta->rra = size[0]--;
		if (size[1] == 0)
			sta->rra = 0;
		sta = sta->next;
		size[1]++;
	}
}

void	give_rb_rrb(stack *stb)
{
	int		size[3];

	size[0] = get_stacklen(stb);
	size[1] = 0;
	while (size[0])
	{
		stb->rb = size[1];
		stb->rrb = size[0]--;
		if (size[1] == 0)
			stb->rrb = 0;
		stb = stb->next;
		size[1]++;
	}
}

int		give_best_cost(stack *stb)
{
	int		best_cost = stb->final_cost;
	while (stb->next)
	{
		if (stb->final_cost < best_cost)
			best_cost = stb->final_cost;
		stb = stb->next;
	}
	return (best_cost);
}

void	move_it(stack *sta, stack *stb)
{
	stack	*stb_save = stb;
	int		cost[4];
	
	ft_index(sta);
	ft_index(stb);
	cost[0] = give_best_cost(stb);
	while (stb_save->final_cost != cost[0])
		stb_save = stb_save->next;
	cost[1] = stb->target_pos;
	cost[2] = get_stacklen(sta);
	if (stb->target_pos > cost[2] / 2)
		while (cost[1]-- > 0)
			ft_rra(&sta);
	else
		while (cost[1]-- > 0)
			ft_ra(&sta);
	cost[3] = stb_save->pos;
	if (stb_save->pos > cost[2] / 2)
		while (cost[3]-- > 0)
			ft_rrb(&stb);
	else 
		while (cost[3]-- > 0)
			ft_rb(&stb);
}

void	apply_cost(stack *sta, stack *stb)
{
	int		len = get_stacklen(stb);

	ft_index(sta);
	ft_index(stb);
	give_ra_rra(sta);
	give_rb_rrb(stb);
	if (stb->pos < len / 2)
		stb->final_cost = stb->rb;
	else
		stb->final_cost = stb->rrb;
	if (sta->pos < len / 2)
		stb->final_cost += sta->ra;
	else
		stb->final_cost += sta->rra;		
}

stack	*find_lastval(stack *sta, int index)
{
	stack	*sta_save;
	int		i = 0;

	sta_save = sta;
	while (i++ < index)
		sta_save = sta_save->next;
	return (sta_save);
}

void	give_costb(stack **sta, stack **stb)
{
	stack *tmpA = *sta;
	stack *tmpB = *stb;
	int		save = 100000;

	while (tmpB)
	{
		tmpA = *sta;
		ft_index(tmpA);
		ft_index(tmpB);
		while (tmpA)
		{
			if (tmpA->value > tmpB->value && tmpA->value < save)
			{
				tmpB->target_pos = tmpA->pos;
				save = tmpA->value;
			}
			tmpA = tmpA->next;			
		}
		tmpB = tmpB->next;
	}
}

void	algo(stack *sta, stack *stb)
{
	while (stb)
	{
		print_stack(sta);
		printf("\n");
		give_costb(&sta, &stb);
		move_it(sta, stb);
		ft_pa(&sta, &stb);
	}
} */
