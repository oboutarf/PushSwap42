/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/15 17:13:02 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NB_CHUNK 4
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

typedef enum boolean
{
    false,
    true
}boolean;

// $ // ----------------------------------------------------------------- // # //
//  Structure des piles A et B
// $ // ----------------------------------------------------------------- // # //

typedef struct stack
{
    int             final_index;
    int             target_pos;
    int             final_cost;
    int             value;
    int             pos;
    int             rra;
    int             rrb;
    int             ra;
    int             rb;
    struct  stack   *next;
}stack;


int		get_origlen(stack *sta, stack *stb);
int     get_stacklen(stack *sta);
int		ft_strlen(char *str);
int     ft_atoi(char *nptr);
int     ft_numlen(int n);

void	chunk_it(stack *sta, stack *stb, int size);
void	what_move_a(stack *sta, stack *stb);
void	give_costb(stack **sta, stack **stb);
void    ft_pa(stack **sta, stack **stb);
void    ft_pb(stack **sta, stack **stb);
void    ft_rr(stack **sta, stack **stb);
void	ft_ss(stack **sta, stack **stb);
void	move_it(int to_move, stack **sta, stack **stb);
void    give_rb_rrb(stack *stb);
void	give_ra_rra(stack *sta);
void    give_target(stack *sta);
void    print_stack(stack *st);
void    ft_index(stack *st);
void    ft_rra(stack **sta);
void    ft_rrb(stack **stb);
void    ft_ra(stack **sta);
void    ft_rb(stack **stb);
void    ft_sa(stack **sta);
void    ft_sb(stack **sta);

booln    fill_stack(stack **stack_a, int ac, char **av);
booln    is_stack_clear(stack *st);
booln    ft_isnumber(char *str);
booln    ft_isdup(char **av);

stack   *elem_addto_stack(stack **st, int x);
stack   *clear_stack(stack *st);
stack   *create_new_stack(void);

#endif