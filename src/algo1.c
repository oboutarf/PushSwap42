/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/04 03:27:26 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"


void		give_rra_rrb(stack **sta, stack **stb)
{
	stack	*sta_save;
	stack	*stb_save;
	int		mid_a = get_stacklen(sta) / 2 + 1;
	int		mid_b = get_stacklen(stb) / 2 + 1;
	int		mid_atmp = mid_a;
	int		mid_btmp = mid_b;

	sta_save = (*sta);
	stb_save = (*stb);
	while (mid_atmp > 0)
	{
		(*sta) = (*sta)->next;
		mid_atmp--;	
	}
	mid_atmp = mid_a - 1;
	while ((*sta) != NULL)
	{
		(*sta)->rra = mid_atmp;
		// printf("(*sta)->value is: %d\n", (*sta)->value);
		// printf("(*sta)->rra is: %d\n", (*sta)->rra);
		(*sta) = (*sta)->next;
		mid_atmp--;
	}
	printf("\n\n\n");
	(*sta) = sta_save;
	while (mid_btmp > 0)
	{
		(*stb) = (*stb)->next;
		mid_btmp--;	
	}
	mid_btmp = mid_b - 1;
	while ((*stb) != NULL)
	{
		(*stb)->rrb = mid_btmp;
		// printf("(*stb)->value is: %d\n", (*stb)->value);
		// printf("(*stb)->rrb is: %d\n", (*stb)->rrb);
		(*stb) = (*stb)->next;
		mid_btmp--;
	}
	printf("\n\n\n");
	(*stb) = stb_save;
}

void		give_ra_rb(stack **sta, stack **stb)
{
	int		mid_a = get_stacklen(sta) / 2;
	int		mid_b = get_stacklen(stb) / 2;
	int		orig_a = 1;
	int		orig_b = 1;

	while (mid_a > 0)
	{
		(*sta)->ra = orig_a;
		// printf("(*sta)->value is: %d\n", (*sta)->value);
		// printf("(*sta)->ra is: %d\n", (*sta)->ra);
		(*sta) = (*sta)->next;
		orig_a++;
		mid_a--;
	}
	printf("\n\n\n");
	while (mid_b > 0)
	{
		(*stb)->rb = orig_b;
		// printf("(*stb)->value is: %d\n", (*stb)->value);
		// printf("(*stb)->rb is: %d\n", (*stb)->rb);
		(*stb) = (*stb)->next;
		orig_b++;
		mid_b--;
	}
	printf("\n\n\n");
}

void	fnlcosts_mid_up(stack **sta, stack **stb, int mid)
{
	stack	*save_sta = (*sta);
	stack	*save_stb = (*stb);
	int		final_cost = 0;
	int		tmp_mid1 = mid;
	int		tmp_mid2 = mid;
	
	give_ra_rb(sta, stb);
	give_rra_rrb(sta, stb);
	while ((*stb)->next != NULL && tmp_mid1 > 0)
	{
		tmp_mid2 = mid;
		while ((*sta)->next != NULL && tmp_mid2 > 0)
		{
			final_cost = 0;
			if ((*stb)->value < (*sta)->value)
			{
				final_cost = (*sta)->ra + (*stb)->rb;
				(*stb)->final_cost1 = final_cost;
				printf("(*sta)->value: %d\n", (*sta)->value);
				printf("(*sta)->ra: %d\n", (*sta)->ra);
				printf("(*sta)->rra: %d\n\n", (*sta)->rra);
				printf("(*stb)->value: %d\n", (*stb)->value);
				printf("(*stb)->rb: %d\n", (*stb)->rb);
				printf("(*stb)->rrb: %d\n", (*sta)->rrb);
				printf("(*stb)->final_cost1: %d\n\n\n\n", (*stb)->final_cost1);
			}
			printf("--------------------------------\n\n");
			(*sta) = (*sta)->next;
			tmp_mid2--;
		}
		(*sta) = save_sta;
		(*stb) = (*stb)->next;
		tmp_mid1--;
	}
	(*sta) = save_sta;
	(*stb) = save_stb;
}

/* void	fnlcosts_mid_down(stack **sta, stack **stb)
{
	
} */

void	give_order_sta(stack **sta)
{
	if ((*sta)->value > (*sta)->next->value)
		ft_sa(sta);
}
 
void	start_max(stack **sta, stack **stb, int tmp_size)
{
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
			give_order_sta(sta);
			last_idx -= quadx4;
			cmpr -= quadx4;
		}
		else
			ft_rb(stb);
		size -= 1;
	}
	give_ra_rb(sta, stb);
}

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
	start_max(sta, stb, tmp_size);
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
	int		tmp_size = size - 2;
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