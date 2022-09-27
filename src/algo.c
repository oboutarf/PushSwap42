/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:16 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

int find_zemidl(stack **sta)
{
    stack   *start;
    int     zemidl;
    
    zemidl = 0;
    start = (*sta);
    zemidl = get_stacklen(sta) / 2;
    while ((*sta)->next != NULL)
    {
        if ((*sta)->target_pos == zemidl)
        {
            zemidl = (*sta)->value;
            *sta = start;
            return (zemidl);
        }
        (*sta) = (*sta)->next;
    }
    (*sta) = start;
    return (zemidl);
}

// $ // ----------------------------------------------------------------- // # //

int     count_number(stack **sta, int n_len)
{
    stack   *start;
    int     count;
    
    count = 0;
    start = (*sta);
    while (*sta)
    {
        if (ft_numlen((*sta)->value) == n_len)
            count++;
        (*sta) = (*sta)->next;
    }
    (*sta) = start;
    return (count);
}

// $ // ----------------------------------------------------------------- // # //

void    ob_radix1(stack **sta, stack **stb)
{
    int     stacksize = 0;
    
    stacksize = count_number(sta, 1);
    while ((*sta)->next != NULL && stacksize != 0)
    {
        if (!(ft_numlen((*sta)->value) == 1))
            ft_ra(sta);
        else
        {
            ft_pb(sta, stb);
            stacksize--;
        }
    }
    // ft_sorta1(sta, stb, get_stacklen(sta));
}

// $ // ----------------------------------------------------------------- // # //

void    ft_sorta1(stack **sta, stack **stb, int n_elemA)
{
    stack   **tmp1;
    stack   **tmp2;

    
    
}

// $ // ----------------------------------------------------------------- // # //



// $ // ----------------------------------------------------------------- // # //



// $ // ----------------------------------------------------------------- // # //


void    ob_radix2(stack **sta, stack **stb)
{
    int     stacksize = 0;

    stacksize = count_number(sta, 2);
    while ((*sta)->next != NULL && stacksize != 0)
    {
        if (!(ft_numlen((*sta)->value) == 2))
            ft_ra(sta);
        else
        {
            ft_pb(sta, stb);
            stacksize--;
        }
    }
}

// $ // ----------------------------------------------------------------- // # //

/*
void    ob_radix3(stack **sta)
{

} */

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
