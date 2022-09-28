/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/28 12:33:57 by oboutarf         ###   ########.fr       */
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


void    ob_radix3(stack **sta, stack **stb, int max_index)
{
    int     orig_elem3 = 0;
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
            orig_elem3++;
        }
    }
    ft_sortb1(sta, stb ,orig_elem3, max_index);
}

// $ // ----------------------------------------------------------------- // # //

void    ft_sortb1(stack **sta, stack **stb, int orig_elem3, int max_index)
{
    stack   **tmp2;

    tmp2 = stb;
    while (orig_elem3 > 0)
    {
        if (!((*tmp2)->target_pos == max_index))
            ft_rb(stb);
        else
        {
            ft_pa(sta, stb);
            orig_elem3--;
            max_index--;
        }    
    }
    ft_sortb2(sta, stb, max_index);
}

void    ft_sortb2(stack **sta, stack **stb, int max_index)
{
    stack   **tmp2;
    int     orig_elem2;

    tmp2 = stb;
    orig_elem2 = 0;
    orig_elem2 = count_number(stb, 2);
    while (orig_elem2 > 0)
    {
        if (!((*tmp2)->target_pos == max_index))
            ft_rb(stb);
        else
        {
            ft_pa(sta, stb);
            orig_elem2--;
            max_index--;
        }
    }
    ft_sortb3(sta, stb, max_index);
}

void    ft_sortb3(stack **sta, stack **stb, int max_index)
{
    stack   **tmp2;
    int     orig_elem1;

    tmp2 = stb;
    orig_elem1 = 0;
    orig_elem1 = count_number(stb, 1);
    while (orig_elem1 > 0)
    {
        if (!((*tmp2)->target_pos == max_index))
            ft_rb(stb);
        else
        {
            ft_pa(sta, stb);
            orig_elem1--;
            max_index--;
        }
    }
}

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
