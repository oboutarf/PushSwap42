/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forfive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:52 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/24 16:13:33 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	push_mins(stack **sta, stack **stb)
{
	int		mins;

	mins = 2;
	give_target(*sta);
	while (mins > 0)
	{
		if ((*sta)->final_index == 0 || (*sta)->final_index == 1)
		{
			ft_pb(sta, stb);
			mins--;
		}
		ft_ra(sta);
	}
}

void	choose_wich(stack *sta, stack *stb)
{
	if (stb->value > stb->next->value)
		ft_pa(&sta, &stb);
	else
	{
		ft_rb(&stb);
		ft_pa(&sta, &stb);
	}
	ft_pa(&sta, &stb);
}

void	center_forfive(stack *sta, stack *stb)
{
	push_mins(&sta, &stb);
	center_forthree(sta);
	choose_wich(sta, stb);
}