/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/29 20:37:34 by oboutarf         ###   ########.fr       */
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

void    ob_radix(stack **sta, stack **stb, int size)
{
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 6;
    tmpstacksize = stacksize;
    while (size >= 0)
    {
        count_elem = 0;
        while ((*sta)->next != NULL && count_elem != stacksize)
        {
            if ((*sta)->target_pos >= orig && (*sta)->target_pos <= tmpstacksize)
            {
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            else
                ft_ra(sta);
        }
        orig += stacksize;
        tmpstacksize += stacksize;
    }
}
                // write(1, "", 5);
                // tmpstacksize--;

boolean    rotate_b1(stack **stb, int max_index, int orig_elem)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 5)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem > 0)
        return (false);
    return (false);
}

boolean    revrotate_b1(stack **stb, int max_index, int orig_elem)
{
    stack   **tmp2;

    tmp2 = stb;
    while (size >= 0)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}


void    ft_sortb1(stack **sta, stack **stb, int orig_elem, int max_index)
{
    while (orig_elem > 0)
    {
        if (rotate_b(stb, max_index, orig_elem6) || revrotate_b(stb, max_index, orig_elem6))
        {
            ft_pa(sta, stb);
            orig_elem--;
            max_index--;
        }
    }
    ft_sortb2(sta, stb , max_index);
}

// $ // ----------------------------------------------------------------- // # //



// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //



/* // $ // ----------------------------------------------------------------- // # //

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

    stacksize = count_my_num(stb, min, max)
    while ((*sta) && stacksize != 0)
    {
        if (!())
            ft_ra(sta);
        else
        {
            ft_pb(sta, stb);
            stacksize--;
            orig_elem3++;
        }
    }
} */

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
