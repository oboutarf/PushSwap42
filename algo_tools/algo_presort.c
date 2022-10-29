/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_presort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:56:42 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/29 18:53:47 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

static int	*create_chunk(t_stack *sta, int size)
{
	int		*chunk;

	chunk = malloc(sizeof(int) * 6);
	chunk[0] = 0;
	if (size >= 100)
		chunk[1] = size / 4;
	else if (size >= 7 && size < 100)
		chunk[1] = size / 2;
	else if (size < 7)
		chunk[1] = size;
	chunk[2] = chunk[1];
	chunk[3] = chunk[1];
	chunk[4] = get_stacklen(sta) - 1;
	chunk[5] = chunk[4];
	return (chunk);
}

void	choose_push_or_rotate(t_stack **sta, t_stack **stb, int fifth_chunk)
{
	if ((*sta)->final_index != 0 && (*sta)->final_index != fifth_chunk)
		ft_pb(sta, stb);
	else
		ft_ra(sta);
}

t_stack	*call_algo(t_stack **sta, t_stack **stb)
{
	ft_ra(sta);
	ft_index(*sta);
	ft_index(*stb);
	algo(sta, stb);
	return (*sta);
}

t_stack	*start_process(t_stack *sta, t_stack *stb, int size)
{
	int	*chunk;

	chunk = create_chunk(sta, size);
	while (chunk[4] > 2)
	{
		chunk[2] = chunk[3];
		while (chunk[2] > 0)
		{
			if (get_stacklen(sta) == 2)
				break ;
			if (sta->final_index >= chunk[0] && sta->final_index < chunk[1])
			{
				chunk[2]--;
				chunk[4]--;
				choose_push_or_rotate(&sta, &stb, chunk[5]);
			}
			else
				ft_ra(&sta);
		}
		chunk[0] += chunk[3];
		chunk[1] += chunk[3];
	}
	free(chunk);
	sta = call_algo(&sta, &stb);
	return (sta);
}
