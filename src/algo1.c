/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/30 15:28:35 by oboutarf         ###   ########.fr       */
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

// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  o b__ radix  --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //

void    ob_radix(stack **sta, stack **stb, int size)
{
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 11;
    tmpstacksize = stacksize;
    while (size > 0)
    {
        count_elem = 0;
        while ((*sta)->next != NULL && count_elem != stacksize)
        {
            if ((*sta)->target_pos >= (orig + 1) && (*sta)->target_pos <= tmpstacksize)
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


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  s o r t b  ----------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


boolean    rotate_b(stack **stb, int size, int len_chunk)
{
	int		tmplen_chunk;
    stack   **tmp2;
    
    tmp2 = stb;
    tmplen_chunk = len_chunk;
    while (tmplen_chunk > 0)
    {
        if ((*tmp2)->target_pos == size)
            return (true);
        ft_rb(stb);
        tmplen_chunk--;
    }
    if (len_chunk > 0)
        return (false);
    return (false);
}

boolean    revrotate_b(stack **stb, int size)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == size)
            return (true);
        ft_rrb(stb);
    }
    return (false);
}

void    ft_sortb(stack **sta, stack **stb, int size, int len_chunk)
{
    int     tmpsize = size;
	

    while (tmpsize > 0)
    {
		if (rotate_b(stb, tmpsize, len_chunk) || revrotate_b(stb, tmpsize))
		{
			ft_pa(sta, stb);
			tmpsize--;
        }
    }
}
    // ft_sortb2(sta, stb , max_index);


/* boolean    rotate_b(stack **stb, int size, int len_chunk)
{
    int     tmpsize = size;
    int     tmplen_chunk;
    
    tmplen_chunk = len_chunk;
    while ()    
    {
        if ((*sta)->target_pos == max_index)
            return (true)
        ft_rb()
        chunk++;
        return (false)
    }
}
*/



// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  +++++++++  ----------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


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
