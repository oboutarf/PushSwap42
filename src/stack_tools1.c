/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:21:33 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/24 11:03:12 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

booln   is_stack_clear(stack *st)
{
    if (st == NULL)
        return (clear);
    return (unclear);
}

// $ // ----------------------------------------------------------------- // # //

stack   *elem_addto_stack(stack **st, int x, int index)
{
    stack   *element;

    element = malloc(sizeof(*element));
    if (!element)
    {
        printf("Malloc error !");
        return (NULL);
    }
    element->value = x;
    element->index = index;
    element->cost = 0;
    element->next = *st;
    *st = element;
    return (element);
}

// $ // ----------------------------------------------------------------- // # //

stack   *clear_stack(stack *st)
{
    stack   *element;
    
    if (is_stack_clear(st) == clear)
        return (create_new_stack());
    element = st->next;
    free(st);
    return (clear_stack(element));
}

// $ // ----------------------------------------------------------------- // # //

booln   ft_isnumber(char *str)
{
    int i;
    
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

// $ // ----------------------------------------------------------------- // # //

void     ft_index(stack **st)
{
    stack   *start;
    int     idx;
    
    idx = 0;
    start = *st;
    while (*st != NULL)
    {
        (*st)->index = idx++;
        *st = (*st)->next;
    }
    *st = start;    // Important pour chaque liste permet de garder la position du pointeur//
}

// $ // ----------------------------------------------------------------- // # //

booln   ft_isdup(char **av)
{
    int     i;
    int     j;
    i = 1;
    j = 0;
    while (av[j])
    {
        while (av[i])
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return (1);
            i++;
        }
        j++;
        i = j + 1;
        
    }
    return (0);
}

// $ // ----------------------------------------------------------------- // # //
// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //