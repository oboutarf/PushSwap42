/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draft1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:42:07 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/07 10:49:21 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

// $ // 00000000000000000000000000000000000000000000000000000000000000000 // # //
// $ // ----------------------------------------------------------------- // # //

int find_zemidl(stack **sta)
{
    stack   *start;
    int     zemidl;
    
    zemidl = 0;
    start = (*sta);
    zemidl = get_stacklen(sta) / 2;
    while ((*sta)->next != NULL)
    {
        if ((*sta)->target_pos == zemidl)
        {
            zemidl = (*sta)->value;
            *sta = start;
            return (zemidl);
        }
        (*sta) = (*sta)->next;
    }
    (*sta) = start;
    return (zemidl);
}

// $ // ----------------------------------------------------------------- // # //

int     count_number(stack **sta, int n_len)
{
    stack   *start;
    int     count;
    
    count = 0;
    start = (*sta);
    while (*sta)
    {
        if (ft_numlen((*sta)->value) == n_len)
            count++;
        (*sta) = (*sta)->next;
    }
    (*sta) = start;
    return (count);
}




// compter si la valeur recherchee est plus proche en faisant des ra ou des rra grace a une fonction
// -> Cette derniere prendra en compte la stack a && prendra en parametre la taille ainsi que notre 
// 'count_up' et notre 'count_down'  

// elle prend les elements a partir de l'index median de l'integralite de la stack, pour une stack de 60 nous prenons chaque
// index allant de 30 a 


// 1st step:

/* boolean		give_order_up(stack **sta, int count_up, int count_down)
{
	int		tmp_size = count_down + count_up;
	int		tmp_count = 0;
	stack 	*tmp;

	tmp = (*sta);
	
	
}
 */


/* 
boolean	check_soluce(stack **sta, stack *tmp, int count_down, int count_up)
{
	int		size = get_stacklen(sta);
	int		count = size / 2;
	int		cmpr = count / 2;

	while (tmp->next != NULL)
	{
		if (count > cmpr)
		{
			if (tmp->target_pos == count_down || tmp->target_pos == count_up)
				return (true);
			tmp = tmp->next;
			cmpr++;
		}
		if (count == cmpr)
			return (false);
	}
	return (false);
}

void	ft_move(stack **sta, int count_down, int count_up)
{
	stack 	*tmp = (*sta);

	if (check_soluce(sta, tmp, count_down, count_up))
	{
		while ((*sta)->target_pos != count_up || (*sta)->target_pos != count_up)
			ft_ra(sta);
		return ;
	}
	else
	{
		while ((*sta)->target_pos != count_up || (*sta)->target_pos != count_up)
			ft_rra(sta);
		return ;
	}
}


void	ft_divide(stack **sta, stack **stb, int size)
{
	int count_down = size / 2;
	int count_up = count_down + 1;

	while (size > 0)
	{
		ft_move(sta, count_down, count_up);
		if ((*sta)->target_pos == count_down)
			count_down--;
		else
			count_up++;
		ft_pb(sta, stb);
		size -= 2;
	}
}
 */



// 501 valeurs = 63 000 coups
/* void    ft_divide_sta(stack **sta, stack **stb, int size)
{
	int		count_up = size / 2;
	int		count_down;

	count_down = count_up;
	while (size > 0)
	{
		while ((*sta)->target_pos != count_up)
			ft_ra(sta);
		ft_pb(sta, stb);
		count_up++;
		size--;;
		while ((*sta)->target_pos != count_down - 1)
			ft_ra(sta);
		ft_pb(sta, stb);
		count_down--;
		size--;
	}
}
 */
//	End of 1st step	//


// $ // ----------------------------------------------------------------- // # //

// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  o b__ radix  --------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //

/* int     count_rra(stack **sta, int orig, int size, int stacksize)
{
    int     count_prev = 0;
    stack   *save;
    stack   **tmp1;

    tmp1 = sta;
    save = (*tmp1);
    while (!((*tmp1)->target_pos >= (orig + 1) && (*tmp1)->target_pos <= stacksize))
    {
        if (count_prev == size / 2)
            return (-1);
        check_rra(sta);
        count_prev++;
    }
    (*tmp1) = save;
    return (count_prev);
} */

/*
void    ob_radix(stack **sta, stack **stb, int size)
{
    int     ra_visu = 0;
    int     rra_visu = 0;
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 3;
    tmpstacksize = stacksize;
    while (size > 0)
    {
        count_elem = 0;
        while ((*sta)->next != NULL && count_elem != stacksize)
        {
            rra_visu = count_rra(sta, orig, size, stacksize);
            ra_visu = count_ra(sta, orig, size, stacksize);
            if (!(count_ra(sta, orig, size, stacksize) == -1))
            {
                while (ra_visu > 0)
                {
                    ft_ra(sta);
                    ra_visu--;   
                }
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            if (!(count_rra(sta, orig, size, stacksize) == -1))
            {
                while (rra_visu > 0)
                {
                    ft_rra(sta);
                    rra_visu--;
                }
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            rra_visu = 0;
            ra_visu = 0;
        }
        orig += stacksize;
        tmpstacksize += stacksize;
    }
}
*/

/* int     count_ra(stack **sta, int orig, int size, int stacksize)
{
    int     count_next = 0;
    stack   *tmp1;
    
    tmp1 = (*sta);
    while (!(tmp1->target_pos >= orig + 1 && tmp1->target_pos <= stacksize))
    {
        if (count_next == size / 2)
            return (0);
        tmp1 = tmp1->next;
        count_next++;
    }
    return (count_next);
}


void    ob_radix(stack **sta, stack **stb, int size)
{
    int     ra_visu = 0;
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 6;
    tmpstacksize = stacksize;
    while (size > 0)
    {
        count_elem = 0;
        while ((*sta)->next != NULL && count_elem != stacksize - 1)
        {
            ra_visu = count_ra(sta, orig, size, stacksize);
            if (ra_visu > 0)
            {
                while (!(ra_visu == 0))
                {
                    ft_ra(sta);
                    ra_visu--;
                }
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            else
            {
                while ((*sta)->target_pos > tmpstacksize)
                    ft_rra(sta);
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            ra_visu = 0;
        }
        orig += stacksize;
        tmpstacksize += stacksize;
    }
    if (get_stacklen(sta) == 0)
        ft_pb(sta, stb);
} */

/* void    ob_radix(stack **sta, stack **stb, int size)
{
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 11;
    tmpstacksize = stacksize;
    while (size > 0)
    {
        count_elem = 0;
        while ((*sta)->next != NULL && count_elem != stacksize)
        {
            if ((*sta)->target_pos >= (orig + 1) && (*sta)->target_pos <= tmpstacksize)
            {
                ft_pb(sta, stb);
                count_elem++;
                size--;
            }
            else
                ft_ra(sta);
        }
        orig += stacksize;
        tmpstacksize += stacksize;
    }
} */
                // write(1, "", 5);
                // tmpstacksize--;


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  s o r t b  ----------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //

/* 
boolean    rotate_b(stack **stb, int size, int len_chunk)
{
	int		tmplen_chunk;
    stack   **tmp2;
    
    tmp2 = stb;
    tmplen_chunk = len_chunk;
    while (tmplen_chunk > 0)
    {
        if ((*tmp2)->target_pos == size)
            return (true);
        ft_rb(stb);
        tmplen_chunk--;
    }
    if (len_chunk > 0)
        return (false);
    return (false);
}

boolean    revrotate_b(stack **stb, int size)
{
    stack   **tmp2;

    tmp2 = stb;
    while (ft_numlen((*tmp2)->value) != 1)
    {
        if ((*tmp2)->target_pos == size)
            return (true);
        ft_rrb(stb);
    }
    return (false);
}

void    ft_sortb(stack **sta, stack **stb, int size, int len_chunk)
{
    int     tmpsize = size;
	

    while (tmpsize > 0)
    {
		if (rotate_b(stb, tmpsize, len_chunk) || revrotate_b(stb, tmpsize))
		{
			ft_pa(sta, stb);
			tmpsize--;
        }
    }
} */
    // ft_sortb2(sta, stb , max_index);


/* boolean    rotate_b(stack **stb, int size, int len_chunk)
{
    int     tmpsize = size;
    int     tmplen_chunk;
    
    tmplen_chunk = len_chunk;
    while ()    
    {
        if ((*sta)->target_pos == max_index)
            return (true)
        ft_rb()
        chunk++;
        return (false)
    }
}
*/


/* void	start_max(stack **sta, stack **stb, int tmp_size)
{	
	// int		save_size = tmp_size;	
	// int		eight = tmp_size / 300;
	int		size = tmp_size;
	// int		tmp1_size = tmp_size;
	int		mid = tmp_size / 2;
	int		quad = mid / 2;
	int		quadquad = quad / 2;
	int		quadquadquad = quadquad / 2;
	int		quadx4 = quadquadquad / 2;
	int		cmpr = mid + quad + quadquad + quadquadquad + quadx4;
	int		last_idx = tmp_size;
	
	size *= 2;
	while (size > 0)
	{
		if ((*stb)->target_pos >= cmpr && (*stb)->target_pos <= last_idx)
		{
			ft_pa(sta, stb);
			if ((*sta)->value > (*sta)->next->value)
				ft_sa(sta);
			last_idx -= quadx4;
			cmpr -= quadx4;
		}
		else
			ft_rb(stb);
		size -= 1;
	}
	// what_move((*sta), (*stb));
} */


// $ // 110010110000111001011000011100101100001110010110000111001011000011 // # //
// $ // -----------------------  +++++++++  ----------------------------- // # //
// $ // 1001011000011100101100001110010110000111001011000011100101100001 // # //


// $ // ----------------------------------------------------------------- // # //



// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //


// $ // ----------------------------------------------------------------- // # //



// $ // ----------------------------------------------------------------- // # //

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
    /* print_stack(stack_a);							
	printf("\n# ^ ------------------------------  5A #\n");
    printf("# |  S T A C K  A  ------------------- #\n");
	printf("# | ---------------------------------- #\n\n\n\n\n");

	print_stack(stack_b);				
	//clear_stack(stack_a)
	printf("\n# ^ ------------------------------  5B #\n");
	printf("# |  S T A C K  B  ------------------- #\n");	
	printf("# | ---------------------------------- #\n\n\n\n");



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
 