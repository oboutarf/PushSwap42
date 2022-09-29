/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:59:44 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/29 17:59:51 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"




























// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //

/* int     count_my_num(stack **stb, int min, int max)
{
    int     count = 0;
    stack   *start;
    stack   **tmp2;

    tmp2 = stb;
    start = (*stb);
    while ((*tmp2)->next != NULL)
    {
        if ((*tmp2)->value >= min || <= max)
             count++;
        (*tmp2) = (*tmp2)->next;
    }
    return (count);
}

// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 1 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b1(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 5)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false);
    return (false);
}

boolean    revrotate_b1(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 5)
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
    int     qcent = 599;
    int     ccent = 500;

    orig_elem6 = count_my_num(stb, qcent, ccent);
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


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 2 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b2(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 4)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

boolean    revrotate_b2(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

void    ft_sortb2(stack **sta, stack **stb, int orig_elem, int max_index)
{
    int     tcentmax = 499
    int     tcentmin = 400

    while (orig_elem > 0)
    {
        if (rotate_b(stb, max_index, orig_elem6) || revrotate_b(stb, max_index, orig_elem6))
        {
            ft_pa(sta, stb);
            orig_elem--;
            max_index--;
        }
    }
    ft_sortb3(sta, stb , max_index);
}


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 3 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b3(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 3)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

boolean    revrotate_b3(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

void    ft_sortb3(stack **sta, stack **stb, int orig_elem, int max_index)
{
    int     qcent = 399;
    int     ccent = 300;
    
    while (orig_elem > 0)
    {
        if (rotate_b(stb, max_index, orig_elem6) || revrotate_b(stb, max_index, orig_elem6))
        {
            ft_pa(sta, stb);
            orig_elem--;
            max_index--;
        }
    }
    ft_sortb4(sta, stb , max_index);
}


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 4 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b4(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 2)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

boolean    revrotate_b4(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

void    ft_sortb4(stack **sta, stack **stb, int orig_elem, int max_index)
{
    int     qcent = 299;
    int     ccent = 200;
    
    while (orig_elem > 0)
    {
        if (rotate_b(stb, max_index, orig_elem6) || revrotate_b(stb, max_index, orig_elem6))
        {
            ft_pa(sta, stb);
            orig_elem--;
            max_index--;
        }
    }
    ft_sortb5(sta, stb , max_index);
}


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 5 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b5(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (((*tmp2)->value / 100) % 10 == 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

boolean    revrotate_b5(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

void    ft_sortb5(stack **sta, stack **stb, int orig_elem, int max_index)
{
    int     qcent = 199;
    int     ccent = 100;

    while (orig_elem > 0)
    {
        if (rotate_b(stb, max_index, orig_elem6) || revrotate_b(stb, max_index, orig_elem6))
        {
            ft_pa(sta, stb);
            orig_elem--;
            max_index--;
        }
    }
    ft_sortb6(sta, stb , max_index);
}


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------- s o r t b + 6 --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b6(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) == 2)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

boolean    revrotate_b6(stack **stb, int max_index, int orig_elem6)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == max_index)
            return (true);
        ft_rrb(stb);
    }
    if (orig_elem6 > 0)
        return (false); 
    return (false);
}

void    ft_sortb6(stack **sta, stack **stb, int orig_elem, int max_index)
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
    return ;
} */
// $ // ----------------------------------------------------------------- // # //


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //
// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //





























/* void    ft_sortb2(stack **sta, stack **stb, int max_index)
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



// $ // ----------------------------------------------------------------- // # //

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
} */

// $ // -------------------------+++++++++------------------------------+ // # //
// $ //   ---------------------+++ E N D +++---------------------------+  // # //
// $ // -------------------------+++++++++------------------------------+ // # //
