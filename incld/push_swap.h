/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/27 13:00:34 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NB_CHUNK 4
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


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

typedef struct stack
{
    int             final_index;
    int             final_cost;
    int             next_pos;
    int             value;
    int             pos;
    struct  stack   *next;
}stack;


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

int		search_prev(stack *sta, int index_of_current_node);
int		search_lowcost(stack *stb);
int     get_stacklen(stack *sta);
int		ft_strlen(char *str);
int     ft_atoi(char *nptr);
int     ft_numlen(int n);
void	calc_final_cost(stack *sta, stack *stb, int sta_len, int stb_len);
void	choose_best_cost(stack *sta, stack *stb, int *all_costs);
void	move_it(int to_move, stack **sta, stack **stb);
void	start_process(stack *sta, stack *stb, int size);
void	center_forfive(stack *sta, stack *stb);
void	instruct_b(stack *sta, stack *stb);
void	algo(stack **sta, stack **stb);
void	reset_instruct_B(stack *stb);
void    center_forthree(stack *sta);
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