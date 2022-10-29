/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forfive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:52 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/29 21:29:16 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

t_boolean	choose_direction(t_stack *sta, int size)
{
	if ((sta->final_index == 0 || sta->final_index == 1)
		&& sta->pos <= size)
		return (true);
	else
		return (false);
}

t_stack	*exec_moves(t_stack *sta_func, t_stack **sta, t_stack **stb, int search)
{
	int		size;

	size = 2;
	if (choose_direction(sta_func, size))
		while ((*sta)->value != search)
			ft_ra(sta);
	else
		while ((*sta)->value != search)
			ft_rra(sta);
	ft_pb(sta, stb);
	return ((*sta));
}

void	search_low_elems(t_stack **sta, t_stack **stb)
{
	t_stack		*sta_func;

	sta_func = (*sta);
	ft_index(sta_func);
	while (sta_func)
	{
		if (sta_func->final_index == 0 || sta_func->final_index == 1)
		{
			sta_func = exec_moves(sta_func, sta, stb, sta_func->value);
		}
		else
			sta_func = sta_func->next;
	}
}

t_stack	*center_forfive(t_stack **sta, t_stack **stb)
{
	int		count;

	count = 2;
	search_low_elems(sta, stb);
	(*sta) = center_forthree(*sta);
	if ((*stb)->final_index > (*stb)->next->final_index)
		while (count-- > 0)
			ft_pa(sta, stb);
	else
	{
		ft_sb(stb);
		while (count-- > 0)
			ft_pa(sta, stb);
	}
	return ((*sta));
}
