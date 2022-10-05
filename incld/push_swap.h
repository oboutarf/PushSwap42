/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/05 16:30:12 by oboutarf         ###   ########.fr       */
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

# define NB_CHUNK 4

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
    // int             final_cost_rra;
    // int             final_cost_ra;
    int             target_pos;
    int             value;
    int             index;
    int             rra;
    int             rrb;
    int             ra;
    int             rb;
    int             rr;
    int             rrr;
    struct  stack   *next;
}stack;

// $ // 110010110000111001011000011100101100001110010110000111001011000011       // # //
// $ // -----------------------------------------------------------------       // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001       // # //
// $ // -----------------------------------------------------------------     // # //
//  Functions of the new version
// $ // -----------------------------------------------------------------   // # //
// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


int     count_number(stack **sta, int n_len);
int     get_stacklen(stack *sta);
int     min_elem(stack **sta);
int     max_elem(stack **sta);
int		ft_strlen(char *str);
int     ft_atoi(char *nptr);
int     ft_numlen(int n);

stack	*give_ra_rra(stack *sta);
stack	*give_rb_rrb(stack *stb);
void	move_now(stack **sta, stack **stb, int tmp_ra_cheap, int tmp_rb_cheap);
void	what_move(stack *sta, stack *stb);
void    ft_div(stack **sta, stack **stb, int size);
void	instructs_achiev(stack **sta, stack **stb);
void	give_ra_rb(stack **sta, stack **stb);
void    ft_rrr(stack **sta, stack **stb);
void    ft_pa(stack **sta, stack **stb);
void    ft_pb(stack **sta, stack **stb);
void    ft_rr(stack **sta, stack **stb);
void	ft_ss(stack **sta, stack **stb);
void    give_target(stack *sta);
void    print_stack(stack *st);
void    ft_index(stack **st);   // bug d'index!!! A corriger.
void    ft_rra(stack **sta);
void    ft_rrb(stack **stb);
void    ft_ra(stack **sta);
void    ft_rb(stack **stb);
void    ft_sa(stack **sta);
void    ft_sb(stack **sta);

booln    fill_stack(stack **stack_a, int ac, char **av);
booln    ft_isnumber(char *str);
booln    ft_isdup(char **av);
booln    is_stack_clear(stack *st);
stack   *elem_addto_stack(stack **st, int x, int index);
stack   *clear_stack(stack *st);
stack   *create_new_stack(void);


// $ // 110010110000111001011000011100101100001110010110000111001011000011       // # //
// $ // -----------------------------------------------------------------       // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001       // # //
// $ // -----------------------------------------------------------------     // # //
//  Functions of the old version
// $ // -----------------------------------------------------------------   // # //
// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //

boolean	check_soluce(stack **sta, stack *tmp, int count_down, int count_up);
void    ft_sortb2(stack **sta, stack **stb, int orig_elem5, int max_index);
void    ft_sortb3(stack **sta, stack **stb, int orig_elem4, int max_index);
void    ft_sortb4(stack **sta, stack **stb, int orig_elem3, int max_index);
void    ft_sortb5(stack **sta, stack **stb, int orig_elem2, int max_index);
void    ft_sortb6(stack **sta, stack **stb, int orig_elem1, int max_index);
void    ob_radix(stack **sta, stack **stb, int size);
void    ob_radix2(stack **sta, stack **stb);
void    ob_radix3(stack **sta, stack **stb);
void    ob_radix4(stack **sta, stack **stb);
void    ob_radix5(stack **sta, stack **stb);
void    ob_radix6(stack **sta, stack **stb);
boolean    rotate_b2(stack **stb, int max_index, int orig_elem5);
boolean    revrotate_b2(stack **stb, int max_index, int orig_elem5);
boolean    rotate_b3(stack **stb, int max_index, int orig_elem4);
boolean    revrotate_b3(stack **stb, int max_index, int orig_elem4);
boolean    rotate_b4(stack **stb, int max_index, int orig_elem3);
boolean    revrotate_b4(stack **stb, int max_index, int orig_elem3);
boolean    rotate_b5(stack **stb, int max_index, int orig_elem2);
boolean    revrotate_b5(stack **stb, int max_index, int orig_elem2);
boolean    rotate_b6(stack **stb, int max_index, int orig_elem1);
boolean    revrotate_b6(stack **stb, int max_index, int orig_elem1);
void       ft_sortb(stack **sta, stack **stb, int size, int len_chunk);
boolean    revrotate_b(stack **stb, int size);
boolean    rotate_b(stack **stb, int size, int len_chunk);
int     find_zemidl(stack **sta);

// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // ----------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //
// $ // 110010110000111001011000011100101100001110010110000111001011001 // # //
// $ // -------------------------------------------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101110 // # //

#endif