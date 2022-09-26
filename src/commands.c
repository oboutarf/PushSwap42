/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:54:30 by oscobou           #+#    #+#             */
/*   Updated: 2022/09/26 14:03:47 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

void    ft_sa(stack **sta)
{
    stack       *save;
    stack       *tmp;

    if (!*sta || (*sta)->next == NULL)
        return ;
    tmp = (*sta);
    (*sta) = (*sta)->next;
    save = (*sta)->next;
    (*sta)->next = tmp;
    tmp->next = save;
}

// $ // ----------------------------------------------------------------- // # //

void    ft_sb(stack **stb)
{
    stack       *save;
    stack       *tmp;

    if (!*stb || (*stb)->next == NULL)
        return ;
    tmp = (*stb);
    (*stb) = (*stb)->next;
    save = (*stb)->next;
    (*stb)->next = tmp;
    tmp->next = save;
}

// $ // ----------------------------------------------------------------- // # //
/*
void	ft_ss(stack **sta, stack **stb)
{
	
}
*/
// $ // ----------------------------------------------------------------- // # //

void    ft_pb(stack **sta, stack **stb)
{
    stack   *tmp;

    if (*sta == NULL)
        return ;
    if (*stb == NULL)
    {
        (*stb) = (*sta);
        (*sta) = (*sta)->next;
        (*stb)->next = NULL;
        return ;
    }
    tmp = (*sta)->next;
    (*sta)->next = (*stb);
    (*stb) = (*sta);
    (*sta) = tmp;
}

// $ // ----------------------------------------------------------------- // # //

void    ft_pa(stack **sta, stack **stb)
{
   stack   *tmp;

    if (*stb == NULL)
        return ;
    if (*sta == NULL)
    {
        (*sta) = (*stb);
        (*stb) = (*stb)->next;
        (*sta)->next = NULL;
        return ;
    }
    tmp = (*stb)->next;
    (*stb)->next = (*sta);
    (*sta) = (*stb);
    (*stb) = tmp;
}

// $ // ----------------------------------------------------------------- // # //

void    ft_ra(stack **sta)
{
    stack   *save_a;
    stack   *tmp;

    if (!(*sta))
        return ;
    save_a = (*sta);
    tmp = (*sta)->next;
    // printf("tmp %d\n", (*sta)->value);
    // printf("tmp %d\n", tmp->value);
    while ((*sta)->next != NULL)
        (*sta) = (*sta)->next;
    (*sta)->next = save_a;
    save_a->next = NULL;
    (*sta) = tmp; 
}

// $ // ----------------------------------------------------------------- // # //

void    ft_rb(stack **stb)
{
    stack   *save_b;
    stack   *tmp;

    if (!(*stb))
        return ;
    save_b = (*stb);
    tmp = (*stb)->next;
    while ((*stb)->next != NULL)
        (*stb) = (*stb)->next;
    (*stb)->next = save_b;
    save_b->next = NULL;
    (*stb) = tmp; 
}

/*

// $ // ----------------------------------------------------------------- // # //

void    ft_rr(stack **sta, stack **stb)
{
    
}

*/

// $ // ----------------------------------------------------------------- // # //

void    ft_rra(stack **sta)
{
    stack   **sta_save;
    stack   *save_bottom;
    stack   *tmp;

    if (!(*sta))
        return ;
    sta_save = sta;
    tmp = (*sta);
    while ((*sta_save)->next->next != NULL)
        (*sta_save) = (*sta_save)->next;
    save_bottom = (*sta_save)->next;
    (*sta_save)->next = (NULL);
    (*sta) = save_bottom;
    (*sta)->next = tmp;
}



// $ // ----------------------------------------------------------------- // # //

void    ft_rrb(stack **stb)
{
    stack   **stb_save;
    stack   *save_bottom;
    stack   *tmp;

    if (!(*stb))
        return ;
    stb_save = stb;
    tmp = (*stb);
    while ((*stb_save)->next->next != NULL)
        (*stb_save) = (*stb_save)->next;
    save_bottom = (*stb_save)->next;
    (*stb_save)->next = (NULL);
    (*stb) = save_bottom;
    (*stb)->next = tmp;
}

/*
// $ // ----------------------------------------------------------------- // # //

void    ft_rrr(stack **sta, stack **stb)
{

}

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
 */