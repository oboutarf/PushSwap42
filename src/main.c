/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscobou <oscobou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/09/22 22:43:43 by oscobou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// $ // ----------------------------------------------------------------- // # //
//	Prototype main avec les arguments
// $ // ----------------------------------------------------------------- // # //

int     main(int ac, char **av)
{
	printf("Project: push_swap\n\n\n\n\n\n\n\n");

	stack	*stack_a;											//->	initialisation de la pile a
    stack   *stack_b;											//->	initialisation de la pile b
	stack_a = NULL;												//->	La pile A prend la valeur "NULL"
    stack_b = NULL;												//->	La pile B prend la valeur "NULL"


    if (ft_isdup(av))											//->	Verification de possibles doublons dans les arguments
        return (write(2, "error\n", 6), 0);						//->	Si la verification echoue on renvoi "error"
    if (!(fill_stack(&stack_a, ac - 1, av)))					//->	Transvasement des arguments dans la stack A
        return (write(2, "error\n", 6), 0);		    			//->	Si le transvasement echoue on renvoi "error"
    //  ft_sa(&stack_a);										//->	Nous effectuons la commande 'sa' en lui envoyant l'adresse du debut de la stack A 
    ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
    
	print_stack(stack_a);
    printf("\n# ^ ------------------------------ 1a #\n");
    printf("# | S T A C K  A  -------------------  #\n");
	printf("# | --------------------------------  #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------ 1b #\n");
	printf("# |  S T A C K  B  ------------------  #\n");	
	printf("# | --------------------------------  #\n\n\n\n\n\n\n");

    ft_index(&stack_a);											
    ft_index(&stack_b);											
	ft_rb(&stack_b);
    print_stack(stack_a);							

	printf("\n# ^ ------------------------------ 2a #\n");
    printf("# |  S T A C K  A  ------------------  #\n");
	printf("# | --------------------------------  #\n\n\n\n\n");

	//  ft_index(&stack_a);
	print_stack(stack_b);				
	//clear_stack(stack_a);

	printf("\n# ^ ------------------------------ 2b #\n");
	printf("# |  S T A C K  B  ------------------  #\n");	
	printf("# | --------------------------------  #\n\n\n\n\n\n\n");
				
    return (1);
}






// $ // ----------------------------------------------------------------- // # //
//      Explication des commandes autorisees pour le projet 
// $ // ----------------------------------------------------------------- // # //

// void sa(stack **stack_a, stack **stack_b);   //  Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
// void sb(stack **stack_a, stack **stack_b);   //  Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun
// void ss(stack **stack_a, stack **stack_b);   //  sa et sb en même temps.

// void pa(stack **stack_a, stack **stack_b);   //  Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
// void pb(stack **stack_a, stack **stack_b);   //  Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.

// void ra(stack **stack_a, stack **stack_b);   //  Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
// void rb(stack **stack_a, stack **stack_b);   //  Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
// void rr(stack **stack_a, stack **stack_b);   //  ra et rb en même temps.

// void rra(stack **stack_a, stack **stack_b);  //  Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
// void rrb(stack **stack_a, stack **stack_b);  //  Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
// void rrr(stack **stack_a, stack **stack_b);  //  rra et rrb en même temps.

// $ // ----------------------------------------------------------------- // # //
// $ // ----------------------------------------------------------------- // # //

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
 