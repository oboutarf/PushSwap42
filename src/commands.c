/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:54:30 by oscobou           #+#    #+#             */
/*   Updated: 2022/09/22 19:59:25 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

void    ft_sa(stack **st)
{
    stack       *save;
    stack       *tmp;

    if (!*st || (*st)->next == NULL)
        return ;
    tmp = (*st);
    (*st) = (*st)->next;
    save = (*st)->next;
    (*st)->next = tmp;
    tmp->next = save;
}

// $ // ----------------------------------------------------------------- // # //

void    ft_sb(stack **st)
{
    stack       *save;
    stack       *tmp;

    if (!*st || (*st)->next == NULL)
        return ;
    tmp = (*st);
    (*st) = (*st)->next;
    save = (*st)->next;
    (*st)->next = tmp;
    tmp->next = save;
}

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

/*
// $ // ----------------------------------------------------------------- // # //

void    rb(stack **st)
{

}


// $ // ----------------------------------------------------------------- // # //

void    rr(int ac, char **av)
{
    
}

// $ // ----------------------------------------------------------------- // # //

void    rra(int ac, char **av)
{

}

// $ // ----------------------------------------------------------------- // # //

void    rrb(int ac, char **av)
{
    
}

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
 */