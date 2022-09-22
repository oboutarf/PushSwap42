/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/22 22:31:41 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// $ // ----------------------------------------------------------------- // # //
//  Structure avec type enum 
// $ // ----------------------------------------------------------------- // # //

typedef enum booln
{
    unclear,
    clear
}booln;

// $ // ----------------------------------------------------------------- // # //
//  Structure des piles A et B
// $ // ----------------------------------------------------------------- // # //

typedef struct stack
{
    int             value;
    int             index;
    int             cost;
    struct  stack   *next;
}stack;                

// $ // ----------------------------------------------------------------- // # //
//  Fonctions de type stack
// $ // ----------------------------------------------------------------- // # //

stack   *elem_addto_stack(stack **st, int x, int index);
stack   *create_new_stack(void);
stack   *clear_stack(stack *st);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions des commandes autorisees
// $ // ----------------------------------------------------------------- // # //

void    ft_pa(stack **sta, stack **stb);
void    ft_pb(stack **sta, stack **stb);
void    print_stack(stack *st);
void    ft_index(stack **st);
void    ft_ra(stack **sta);
void    ft_rb(stack **stb);
void    ft_sa(stack **st);
void    ft_sb(stack **st);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions de type booln
// $ // ----------------------------------------------------------------- // # //

booln    fill_stack(stack **stack_a, int ac, char **av);
booln    is_stack_clear(stack *st);
booln    ft_isnumber(char *str);
booln    ft_isdup(char **av);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions libft
// $ // ----------------------------------------------------------------- // # //

int		ft_strlen(char *str);
int     ft_atoi(char *nptr);

// $ // ----------------------------------------------------------------- // # //


#endif