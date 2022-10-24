/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forthree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:56 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/24 15:00:49 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void       center_forthree(stack *sta)
{
    give_target(sta);
    if (sta->final_index == 1 && sta->next->final_index == 0 && sta->next->next->final_index == 2)
        ft_sa(&sta);
    else if (sta->final_index == 1 && sta->next->final_index == 2 && sta->next->next->final_index == 0)
        ft_rra(&sta);
    else if (sta->final_index == 2 && sta->next->final_index == 0 && sta->next->next->final_index == 1)
        ft_ra(&sta);
    else if (sta->final_index == 2 && sta->next->final_index == 1 && sta->next->next->final_index == 0)
    {
        ft_sa(&sta);
        ft_rra(&sta);
    }
    else if (sta->final_index == 0 && sta->next->final_index == 2 && sta->next->next->final_index == 1)
    {
        ft_rra(&sta);
        ft_sa(&sta);
    }
}