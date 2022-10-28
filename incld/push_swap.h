/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 18:30:08 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum booln
{
	unclear,
	clear
}t_booln;

typedef enum boolean
{
	false,
	true
}t_boolean;

typedef struct stack
{
	int				final_index;
	int				final_cost;
	int				next_pos;
	int				value;
	int				pos;
	struct stack	*next;
}t_stack;

void	ft_pa(t_stack **sta, t_stack **stb);
void	ft_pb(t_stack **sta, t_stack **stb);
void	ft_rr(t_stack **sta, t_stack **stb);
void	ft_ss(t_stack **sta, t_stack **stb);
void	ft_rra(t_stack **sta);
void	ft_rrb(t_stack **stb);
void	ft_ra(t_stack **sta);
void	ft_rb(t_stack **stb);
void	ft_sa(t_stack **sta);
void	ft_sb(t_stack **sta);
void	calc_final_cost(t_stack *sta, t_stack *stb, int sta_len, int stb_len);
void	choose_best_cost(t_stack *sta, t_stack *stb, int *all_costs);
void	move_it(int to_move, t_stack **sta, t_stack **stb);
void	start_process(t_stack *sta, t_stack *stb, int size);
void	center_forfive(t_stack **sta, t_stack **stb);
void	instruct_b(t_stack *sta, t_stack *stb);
void	algo(t_stack **sta, t_stack **stb);
void	reset_instruct_B(t_stack *stb);
void	center_forthree(t_stack *sta);
void	give_target(t_stack *sta);
void	print_stack(t_stack *st);
void	ft_index(t_stack *st);
int		search_prev(t_stack *sta, int index_of_current_node);
int		search_lowcost(t_stack *stb);
int		get_stacklen(t_stack *sta);
int		ft_strlen(char *str);
int		ft_atoi(char *nptr);
int		ft_numlen(int n);
t_booln	fill_stack(t_stack **t_stack_a, int ac, char **av);
t_booln	is_stack_clear(t_stack *st);
t_booln	ft_isnumber(char *str);
t_booln	ft_isdup(char **av);
t_stack	*elem_addto_stack(t_stack **st, int x);
t_stack	*clear_stack(t_stack *st);
t_stack	*create_new_stack(void);

#endif