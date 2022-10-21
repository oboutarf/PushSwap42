/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/20 10:53:14 by oscobou          ###   ########.fr       */
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
    int             final_cost;
    int             next_pos;
    int             value;
    int             pos;
    struct  stack   *next;
}stack;


// $ // ----------------------------------------------------------------- // # //
//  Foncions pour les Moves
// $ // ----------------------------------------------------------------- // # //

void    ft_pa(stack **sta, stack **stb);
void    ft_pb(stack **sta, stack **stb);
void    ft_rr(stack **sta, stack **stb);
void	ft_ss(stack **sta, stack **stb);
void    ft_rra(stack **sta);
void    ft_rrb(stack **stb);
void    ft_ra(stack **sta);
void    ft_rb(stack **stb);
void    ft_sa(stack **sta);
void    ft_sb(stack **sta);

// $ // ----------------------------------------------------------------- // # //
//  Foncions Pre-tri et Algo
// $ // ----------------------------------------------------------------- // # //

int		search_Prev(stack *sta, int index_of_current_node);
int		Search_LowCost(stack *stb);
int     get_stacklen(stack *sta);
int		ft_strlen(char *str);
int     ft_atoi(char *nptr);
int     ft_numlen(int n);
void	chunk_it(stack *sta, stack *stb, int size);
void	move_it(int to_move, stack **sta, stack **stb);
void	calc_final_cost(stack *sta, stack *stb, int sta_len, int stb_len);
void	move_it(int	to_move, stack **sta, stack **stb);
void	instruct_B(stack *sta, stack *stb);
void	algo(stack **sta, stack **stb);
void	reset_instruct_B(stack *stb);
void    give_target(stack *sta);
void    print_stack(stack *st);
void    ft_index(stack *st);
booln   fill_stack(stack **stack_a, int ac, char **av);
booln   is_stack_clear(stack *st);
booln   ft_isnumber(char *str);
booln   ft_isdup(char **av);
stack   *elem_addto_stack(stack **st, int x);
stack   *clear_stack(stack *st);
stack   *create_new_stack(void);

#endif