/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:15:37 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/21 16:45:02 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// $ // ----------------------------------------------------------------- // # //
//  Structure pour les fonctions renvoyant des types booleen
// $ // ----------------------------------------------------------------- // # //

typedef enum booln
{
    unclear,
    clear
}booln;

// $ // ----------------------------------------------------------------- // # //
//  Definition de la structure de ma pile
// $ // ----------------------------------------------------------------- // # //

//  Pile de base        //
typedef struct stack
{
    int             value;
    int             index;
    int             cost;
    struct  stack   *next;
}stack;                

//  Pile push_swap      //
/* typedef struct stack
{
    int             value;
    int             index;
    int             value;
    int             cost;
    struct stack    *next;   
}stack; */

// $ // ----------------------------------------------------------------- // # //
//  Fonctions de type stack
// $ // ----------------------------------------------------------------- // # //

stack   *elem_addto_stack(stack **st, int x, int index);
stack   *create_new_stack(void);
stack   *clear_stack(stack *st);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions utilisees booln
// $ // ----------------------------------------------------------------- // # //

booln    is_stack_clear(stack *st);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions utilisees booln
// $ // ----------------------------------------------------------------- // # //

void    print_stack(stack *st);

// $ // ----------------------------------------------------------------- // # //
//  Fonctions libft
// $ // ----------------------------------------------------------------- // # //

int     ft_atoi(char *nptr);

// $ // ----------------------------------------------------------------- // # //


#endif