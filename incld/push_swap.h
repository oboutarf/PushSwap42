/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/28 08:11:45 by oscobou          ###   ########.fr       */
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
    int             target_pos;
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

void    ft_sortb1(stack **sta, stack **stb, int orig_elemA);
void    ob_radix3(stack **sta, stack **stb, int orig_elemA);
void    ob_radix2(stack **sta, stack **stb);
void    ob_radix1(stack **sta, stack **stb);
void    ft_rrr(stack **sta, stack **stb);
void    ft_pa(stack **sta, stack **stb);
void    ft_pb(stack **sta, stack **stb);
void    ft_rr(stack **sta, stack **stb);
void	ft_ss(stack **sta, stack **stb);
void    give_target(stack *sta);
void    print_stack(stack *st);
void    ft_index(stack **st);
void    ft_rra(stack **sta);
void    ft_rrb(stack **stb);
void    ft_ra(stack **sta);
void    ft_rb(stack **stb);
void    ft_sa(stack **sta);
void    ft_sb(stack **sta);

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

int     get_stacklen(stack **sta);
int     max_elem(stack **sta);
int     min_elem(stack **sta);
int     find_zemidl(stack **sta);
int		ft_strlen(char *str);
int     ft_atoi(char *nptr);
int     ft_numlen(int n);

// $ // ----------------------------------------------------------------- // # //


#endif