/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:16:55 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/05 00:01:36 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"


// $ // ----------------------------------------------------------------- // # //
//	Prototype main avec les arguments
// $ // ----------------------------------------------------------------- // # //

// $ // ----------------------------------------------------------------- // # //
// $ // ----------------------------------------------------------------- // # //

int     main(int ac, char **av)
{
	/* printf("\n\n:Project: push_swap\n\n"); */
	stack	*stack_a;											
    stack   *stack_b;											
    int     size = 0;
	// int     b_size = 0;
    // int     chunksize = 0;
    
    stack_a = NULL;												
    stack_b = NULL;												

    
    // printf("\nMy mid value is -> %d\n\n", test->value);
    if (ft_isdup(av))											
        return (write(2, "error\n", 6), 0);
    if (!(fill_stack(&stack_a, ac - 1, av)))
        return (write(2, "error\n", 6), 0);
    give_target(stack_a);
    size = get_stacklen(&stack_a);
    // b_size = get_stacklen(&stack_a);
    // chunksize = b_size / 6;
    // printf("%d",get_stacklen(&stack_a));
    
    // printf("0000000000000000000000000000000000000000\n\n");
/* 
    // printf("\n%d\n\n", max_elem(&stack_a));
    // printf("\nM%d\n\n", find_zemidl(&stack_a));
    printf("0000000000000000000000000000000000000000\n\n");

    print_stack(stack_a);
    printf("\n# ^ ------------------------------  0A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  0B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");

    printf("\n\n0000000000000000000000000000000000000000\n\n"); */




    give_target(stack_a);
    ft_div(&stack_a, &stack_b, size);
    give_ra_rra(&stack_a);
    give_rb_rrb(&stack_b);
    what_move(&stack_a, &stack_b);    
    // give_ra_rra(&stack_a);
    // give_rb_rrb(&stack_b);
/*     print_stack(stack_a);
    printf("\n# ^ ------------------------------  1A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    // fnlcosts_mid_up(&stack_a, &stack_b, size / 2);
    printf("\n\n0000000000000000000000000000000000000000\n\n"); 
    printf("\n\n0000000000000000000000000000000000000000\n\n"); 
    printf("\n\n0000000000000000000000000000000000000000\n\n"); 
    printf("\n\n0000000000000000000000000000000000000000\n\n"); 

    print_stack(stack_b);
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  1B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	
	printf("# | ---------------------------------- #\n\n");
 */
    /// DERNIERS ARGUMENTS TESTES A LA COMPILATION !!!!!!!!!!!!!!!!!!!!!!!!!!!!


  ///  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ////////////


    // ft_sortb(&stack_a, &stack_b, b_size, chunksize);

    /* print_stack(stack_a);
    printf("\n# ^ ------------------------------  1A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  1B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	
	printf("# | ---------------------------------- #\n\n");

    printf("\n0000000000000000000000000000000000000000\n\n"); */

    // ob_radix2(&stack_a, &stack_b);
    
    /* print_stack(stack_a);
    printf("\n# ^ ------------------------------  2A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  2B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	

    printf("\n\n0000000000000000000000000000000000000000\n\n"); */

    // ob_radix3(&stack_a, &stack_b);

    /* print_stack(stack_a);
    printf("\n# ^ ------------------------------  3A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  3B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");

    printf("\n\n0000000000000000000000000000000000000000\n\n"); */								

	/* print_stack(stack_a);
    printf("\n# ^ ------------------------------  4A #\n");
    printf("# | S T A C K  A  -------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");
    
    print_stack(stack_b);
    printf("\n# ^ ------------------------------  4B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	
	printf("# | ---------------------------------- #\n\n");

    printf("\n0000000000000000000000000000000000000000\n\n"); */

    //      rajouter en paramètres
    //        les stacks A & B    
                                 //         à 'ft_index'
    /* print_stack(stack_a);							
	printf("\n# ^ ------------------------------  5A #\n");
    printf("# |  S T A C K  A  ------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");

	print_stack(stack_b);				
	//clear_stack(stack_a)
	printf("\n# ^ ------------------------------  5B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	
	printf("# | ---------------------------------- #\n\n\n\n");
    
    printf(" 0000000000000000000000000000000000000000\n\n");
    printf("000000000000000   E N D   0000000000000000\n\n");
    printf(" 0000000000000000000000000000000000000000\n\n"); */
    // print_stack(stack_a);
    // printf("\n\n");
    // print_stack(stack_b);
    return (1);
}


// $ // ----------------------------------------------------------------- // # //
// $ // ----------------------------------------------------------------- // # //

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
 