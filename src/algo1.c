/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/06 22:38:35 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"


stack	*give_ra_rra(stack *sta)
{	
	int		size = get_stacklen(sta);
	int		orig_elem = 0;

	while (size > 0)
	{
		sta->ra = orig_elem;
		sta->rra = size;
		if (orig_elem == 0)
			sta->rra = orig_elem;
		sta = sta->next;
		orig_elem++;
		size--;
	}
	return (sta);
}

stack	*give_rb_rrb(stack *stb)
{	
	int		size = get_stacklen(stb);
	int		orig_elem = 0;

	while (size > 0)
	{
		stb->ra = orig_elem;
		stb->rra = size;
		if (orig_elem == 0)
			stb->rra = orig_elem;
		stb = stb->next;
		orig_elem++;
		size--;
	}
	return (stb);
}

void	redirect_sta(stack *sta, int pos_min_sta)
{
	while (sta->value != pos_min_sta)
		ft_ra(&sta);
	ft_ra(&sta);
}

int		posmin_sta(stack *sta)
{
	stack	*first_pos = sta;
	int		min_val_sta = sta->value;

	while (sta->next)
	{
		if (sta->value < min_val_sta)
			min_val_sta = sta->value;
		sta = sta->next;
	}
	sta = first_pos;
	return (min_val_sta);
}

void	search_elem_back_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{	
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value >= stb.value && last_a->value <= stb.value)
			break ;
		ft_rra(sta);
	}
}

void	search_elem_a(stack **sta, stack stb)
{
	stack	*last_a;

	while (1)
	{	
		last_a = *sta;
		while (last_a->next)
			last_a = last_a->next;
		if ((*sta)->value >= stb.value && last_a->value <= stb.value)
			break ;
		ft_ra(sta);
	}
}

void	choose_which_way_a(stack **sta, stack stb)
{
	stack *last_a;
	
	last_a = *sta;
	while (last_a->next)
		last_a = last_a->next;
	if (stb.value < last_a->value)
		search_elem_back_a(sta, stb);
	else
		search_elem_a(sta, stb);
}

void	what_move_a(stack *sta, stack *stb)
{
	while (stb)
	{
		choose_which_way_a(&sta, *stb);
		ft_pa(&sta, &stb);
	}
	// choose_which_way_a(&sta, *stb);
	// ft_pa(&sta, &stb);
}
 
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

void	maxmin(stack **sta, stack **stb, int tmp_size)
{
	int		count = 2;
	
	while (count > 0)
	{
		while ((*stb)->target_pos != 0 && (*stb)->target_pos != tmp_size)
			ft_rb(stb);
		ft_pa(sta, stb);
		count--;
	}
	ft_rra(sta);
	what_move_a(*sta, *stb);
}

int     count_ra(stack **sta, int orig, int size, int stacksize)
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
	int		tmpsize = size;
    int     tmpstacksize;
    int     stacksize;
    int     orig = 0;
    int     count_elem = 0;

    stacksize = size / 12;
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
	if (get_stacklen(*sta) == 0)
		ft_pb(sta, stb);
	maxmin(sta, stb, tmpsize);
}

void 	ft_div2(stack **sta, stack **stb, int mid, int tmp_size)
{
	while (mid > 0)
	{
		if ((*sta)->target_pos >= 0 || (*sta)->target_pos < mid / 2)
		{
			ft_pb(sta, stb);
			mid--;
		}
		else
			ft_ra(sta);
	}
	maxmin(sta, stb, tmp_size);
}

void	ft_div(stack **sta, stack **stb, int size)
{
	int		tmp_size = size;
	int		mid = size / 2;

 	while (size >= mid)
	{
		while ((*sta)->target_pos < mid)
			ft_ra(sta);
		ft_pb(sta, stb);
		size--;
	}
	ft_div2(sta, stb, mid, tmp_size);
}

void	push_in_chunk(stack **sta, stack **stb)
{
	ft_pb(sta, stb);
}

void	do_chunks(stack *sta, stack *stb)
{
	int		size = get_stacklen(sta) / 8;
	int		tmp2size = size;
	int		tmp1size = size;
	int		orig = 0;

	while (sta)
	{
		while (tmp1size > 0)
		{
			if (!sta)
				return ;
			if (sta->target_pos >= orig && sta->target_pos < size)
			{
				push_in_chunk(&sta, &stb);
				tmp1size--;
			}
			else
				ft_ra(&sta);
		}
		orig += tmp2size;
		tmp1size = tmp2size;
		size += tmp2size;
	}
	maxmin(&sta, &stb, get_stacklen(stb));
}

				// printf("(*sta)->value: %d\n", (*sta)->value);
				// printf("(*sta)->ra: %d\n", (*sta)->ra);
				// printf("(*sta)->rra: %d\n\n", (*sta)->rra);
				// printf("(*stb)->value: %d\n", (*stb)->value);
				// printf("(*stb)->rb: %d\n", (*stb)->rb);
				// printf("(*stb)->rrb: %d\n", (*sta)->rrb);
				// printf("(*stb)->final_cost: %d\n\n\n\n", (*stb)->final_cost);