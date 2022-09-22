/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/22 11:13:45 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// $ // ----------------------------------------------------------------- // # //
//	Prototype main avec les arguments
// $ // ----------------------------------------------------------------- // # //

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

// $ // ----------------------------------------------------------------- // # //



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
booln   fill_stack(stack **stack_a, int ac, char **av)
{
    while (ac > 0)
    {
        *stack_a = elem_addto_stack(stack_a, ft_atoi(av[ac]), ac - 1);
        if (!ft_isnumber(av[ac]))
            return (clear_stack(*stack_a), 0);
        if (!(*stack_a))
            return (clear_stack(*stack_a), 0);
        ac--;
    }
    return (1);
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

void sa(stack **stack_a, stack **stack_b);//Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
void sb(stack **stack_a, stack **stack_b);//Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun
void ss(stack **stack_a, stack **stack_b);//sa et sb en même temps.

void pa(stack **stack_a, stack **stack_b);//Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
void pb(stack **stack_a, stack **stack_b);// Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.

void ra(stack **stack_a, stack **stack_b);//   Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
void rb(stack **stack_a, stack **stack_b);//  Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
void rr(stack **stack_a, stack **stack_b);//ra et rb en même temps.

void rra(stack **stack_a, stack **stack_b);// Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
void rrb(stack **stack_a, stack **stack_b);//  Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
void rrr(stack **stack_a, stack **stack_b);//   rra et rrb en même temps.

// $ // ----------------------------------------------------------------- // # //

int     main(int ac, char **av)
{
	stack	*stack_a;
    // stack   *stack_b;
	stack_a = NULL;
    // stack_b = NULL;



    if (ft_isdup(av))
        return (write(2, "error\n", 6), 0);
    if (!(fill_stack(&stack_a, ac - 1, av)))
        return (write(2, "error\n", 6), 0);
    print_stack(stack_a);
	 printf("# ---------------------------------- #\n\n");

    ft_index(&stack_a);

	clear_stack(stack_a);
	// printf("\n# ---------------------------------- #\n");
    // printf("== STACK A ==\n");
/* 	print_stack(stack_a); */
    return (1);
}

// $ // ----------------------------------------------------------------- // # //
//	Prototype main sans les arguments
// $ // ----------------------------------------------------------------- // # //


/*     printf("----------------------------\n");

    stack  *stack;
    //stack  stack_b;
    stack = create_new_stack();
    print_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    stack = elem_addto_stack(stack, 5);
    stack = elem_addto_stack(stack, 10);
      stack = elem_addto_stack(stack, 15);
    stack = elem_addto_stack(stack, 1110);
    printf("----------------------------\n");
    print_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    printf("----------------------------\n");
    stack = clear_stack(stack);
    if (is_stack_clear(stack) == clear)
        printf("->       stack clear !\n");
    if (is_stack_clear(stack) == unclear)
        printf("->       stack unclear !\n");
    print_stack(stack); */
    
// $ // ----------------------------------------------------------------- // # //
 