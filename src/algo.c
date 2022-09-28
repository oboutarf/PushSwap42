/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/28 08:12:44 by oscobou          ###   ########.fr       */
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
}

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


void    ob_radix3(stack **sta, stack **stb, int orig_elemA)
{
    int     stacksize = 0;

    stacksize = count_number(sta, 3);
    while ((*sta) && stacksize != 0)
    {
        if (!(ft_numlen((*sta)->value) == 3))
            ft_ra(sta);
        else
        {
            ft_pb(sta, stb);
            stacksize--;
            orig_elemA++;
        }
    }
    //ft_sortb1(sta, stb ,orig_elemA);
}

// $ // ----------------------------------------------------------------- // # //

void    ft_sortb1(stack **sta, stack **stb, int orig_elemA)
{
    //stack   **tmp1;
    // int     stacksize;
    int     how_much;
    stack   *start;
    stack   **tmp2;
    
    //tmp1 = sta;
    tmp2 = stb;
    how_much = count_number(stb, 3);
    while (how_much != 0)
    {
        start = (*stb);
        while ((*tmp2)->target_pos == orig_elemA)
        {
            ft_pa(sta, stb);
            how_much--;
        }
        if (ft_numlen((*stb)->next->value) == 2)
        {
            (*stb) = start;
        }
    }
}


// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
