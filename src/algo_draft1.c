/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draft1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/12 18:39:35 by oboutarf         ###   ########.fr       */
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
