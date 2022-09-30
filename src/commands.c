/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:54:30 by oscobou           #+#    #+#             */
/*   Updated: 2022/09/30 20:11:14 by oboutarf         ###   ########.fr       */
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
    write(1, "sa\n", 3);
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
    write(1, "sb\n", 3);
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
    write(1, "pb\n", 3);
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
    write(1, "pa\n", 3);
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
    write(1, "ra\n", 3);
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
    write(1, "rb\n", 3);
    save_b = (*stb);
    tmp = (*stb)->next;
    while ((*stb)->next != NULL)
        (*stb) = (*stb)->next;
    (*stb)->next = save_b;
    save_b->next = NULL;
    (*stb) = tmp; 
}


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //

void    ft_rra(stack **sta)
{
    stack   *tmp;
    stack   *save_bottom;
    stack   *tmp1;

    if (!(*sta))
        return ;
    write(1, "rra\n", 4);
    tmp1 = (*sta);
    tmp = *sta;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    save_bottom = tmp->next;
    tmp->next = (NULL);
    (*sta) = save_bottom;
    (*sta)->next = tmp1;
}

// $ // ----------------------------------------------------------------- // # //

void    ft_rrb(stack **stb)
{
    stack   **stb_save;
    stack   *save_bottom;
    stack   *tmp;

    if (!(*stb))
        return ;
    write(1, "rrb\n", 4);
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