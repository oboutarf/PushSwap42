/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/05 00:59:06 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"


void	give_ra_rra(stack **sta)
{	
	int		size = get_stacklen(sta);
	stack	**sta_save = sta;
	stack	*start = (*sta);
	int		orig_elem = 0;

	while ((*sta_save)->next != NULL)
	{
		(*sta_save)->ra = orig_elem;
		(*sta_save)->rra = size;
		if (orig_elem == 0)
			(*sta_save)->rra = orig_elem;
		// printf("(*sta)->value: %d\n", (*sta)->value);
		// printf("(*sta)->ra: %d\n", (*sta)->ra);
		// printf("(*sta)->rra: %d\n\n\n\n", (*sta)->rra);
		(*sta_save) = (*sta_save)->next;
		orig_elem++;
		size--;
	}
	(*sta) = start;
}

void	give_rb_rrb(stack **stb)
{
	int		size = get_stacklen(stb);
	stack	**stb_save = stb;
	stack	*start = (*stb);
	int		orig_elem = 0;

	while ((*stb_save)->next != NULL)
	{
		(*stb_save)->rb = orig_elem;
		(*stb_save)->rrb = size;
		if (orig_elem == 0)
			(*stb_save)->rrb = orig_elem;
		// printf("(*stb)->value: %d\n", (*stb)->value);
		// printf("(*stb)->rb: %d\n", (*stb)->rb);
		// printf("(*stb)->rrb: %d\n\n", (*stb)->rrb);
		(*stb_save) = (*stb_save)->next;
		orig_elem++;
		size--;
	}
	(*stb) = start;
}

void	move_now(stack **sta, stack **stb, int tmp_ra_cheap, int tmp_rb_cheap)
{
	if (tmp_ra_cheap == 0 && tmp_rb_cheap == 0)
		ft_pa(sta, stb);
	if (tmp_ra_cheap > 0)
	{
		while (tmp_ra_cheap > 0)
		{
			tmp_ra_cheap--;
			ft_ra(sta);
		}
		if (tmp_rb_cheap > 0)
		{	
			while (tmp_rb_cheap > 0)
			{
				tmp_ra_cheap--;
				ft_rb(stb);
			}
		}
		ft_pa(sta, stb);
	}
}

void	what_move(stack **sta, stack **stb)
{
	stack	**sta_save = sta;
	stack	**stb_save = stb;
	// stack	*start_a = (*sta);
	// stack	*start_b = (*stb);
	// int		rest_b = get_stacklen(stb);
	int		rest_a = 0;
	int		i = 0;
	// int		j = 0;

	while ((*sta)->next != NULL)
	{
		rest_a = get_stacklen(sta);
		while (rest_a)
		{
			if ((*stb_save)->value < (*sta_save)->value)
			{
				give_ra_rra(sta);
				give_rb_rrb(stb);
				move_now(sta_save, stb_save, i, (*stb_save)->rb);
				rest_a--;
			}
			else 
			{
				(*sta_save) = (*sta_save)->next;
				// (*stb_save) = (*stb_save)->next;
				i++;
				// j++;
				rest_a--;
			}
		}
		i = 0;
		(*sta_save) = (*sta);
		(*stb_save) = (*stb);
	}
}

/* void	scanf_rrb(stack **sta, stack **stb, int size)
{

} */

// faire une fonction qui calule pour chaque maillon de la pile B l'endroit ou c'est le plus 'cheap'
// de le placer. Un premier scan (qui attribuera une valeur au 'finalcost1') devra avoir lieu pour les 'ra':
// Nous chercherons la premiere valeur superieur a (*stb), dans la mediane superieur de **sta et ensuite nous
// nous additionerons les (*stb)->rb et (*sta)->ra + (1 (pour le pb)), un autre scan devra etre effectue a partir
// de l'autre moitie de la mediane, cherchant des valeurs superieur a notre (*stb) mais cette fois avec les 'rra'
// et donc l'addition de (*stb)->rb et (*sta)->rra + (1 (pour le pb)) donnant nos 'finalcost_rb' aux elements presents a partir de la 
// deuxieme moitie de la mediane.
// Un scan de rrb sera effectue dans un deuxieme temps il additionera comme le scan precedent mais cette fois du
// cote des 'rrb', pour etablir un final_cost_rrb.
// Ensuite une fois nos final_cost_rb et final_costs_rrb etablis, nous savons donc l'elements a push dans la pile A 
// qui coute le moins cher, que ce soit en effectuant des rb ou des rrb (les final_costs_rb et final_costs_rrb serons compare pour savoir
// quelle est la meilleure alternative). Reste donc a Push l'element de notre liste le moins couteux dans la stack A...
// C'est la que cela se complique...
// Nous devons trouver un moyen de garder en memoire la valeur de A que nous cherchons a placer et ensuite creer une fonction qui permet 
// d'executer le nombre de mouvement contenu dans la case 'ra' ou 'rra', dependant de la valeur la moins couteuse. Nous allons donc stocker
// la valeur de (*sta)->value la moins couteuse et ensuite executer les mouvs demande.
// 

/* void	give_order_sta(stack **sta)
{
	if ((*sta)->value > (*sta)->next->value)
		ft_sa(sta);
} */
 
void	start_max(stack **sta, stack **stb, int tmp_size)
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
			last_idx -= quadx4;
			cmpr -= quadx4;
		}
		else
			ft_rb(stb);
		size -= 1;
	}
	// give_ra_rra(sta);
	// give_rb_rrb(stb);
	// ft_rra(sta);
	// scanf_rb(sta, stb, save_size);
}

void	maxmin(stack **sta, stack **stb, int tmp_size)
{
	int		count = 2;

	while (count > 0)
	{
		while ((*stb)->target_pos != 0 && (*stb)->target_pos != tmp_size + 2)
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

				// printf("(*sta)->value: %d\n", (*sta)->value);
				// printf("(*sta)->ra: %d\n", (*sta)->ra);
				// printf("(*sta)->rra: %d\n\n", (*sta)->rra);
				// printf("(*stb)->value: %d\n", (*stb)->value);
				// printf("(*stb)->rb: %d\n", (*stb)->rb);
				// printf("(*stb)->rrb: %d\n", (*sta)->rrb);
				// printf("(*stb)->final_cost: %d\n\n\n\n", (*stb)->final_cost);

/*
void	move_it(stack **sta, stack **stb, int tmp_ra_cheap, int tmp_rb_cheap)
{
	int		all_actions = tmp_ra_cheap + tmp_rb_cheap;

	if (all_actions == 0)
	{
		ft_pa(sta, stb);
		return ;
	}
	while (all_actions > 0)
	{
		while (tmp_rb_cheap > 0)
		{
			ft_rb(stb);
			// printf("rbrbrbrbrb\n");
			tmp_rb_cheap--;
		}
		while (tmp_ra_cheap > 0)
		{
			ft_ra(stb);
			// printf("rarararararara\n");
			tmp_ra_cheap--;
		}
		// printf("(*sta)->value: %d\n", (*sta)->value);
		// printf("(*stb)->value: %d\n\n", (*stb)->value);
		ft_pa(sta, stb);
	}	
}

void	scanf_rb(stack **sta, stack **stb, int size)
{
	int		tmp_ra_cheap = (*sta)->ra;
	int		tmp_rb_cheap = (*sta)->rb;
	int		tmp_size = size;     //\\ ___ _ ___ "/ 2" pour l'implementation des 'rrb' ___ _ ___ //
	stack	*sta_save;
	int	i;
	i = 0;
	// int		mid = size / 2;
	// int		tmp_mid = mid;

	sta_save = (*sta);
	while (tmp_size > 0)
	{
		while ((*sta) != NULL)
		{
			if ((*stb)->value < (*sta)->value)  /// 	rajouter aussi les rr et rrr
			{
				// (*stb)->final_cost_rb = (*sta)->ra + (*stb)->rb;
				give_ra_rra(sta);
				give_rb_rrb(stb);
				tmp_ra_cheap = (*sta)->ra;
				tmp_rb_cheap = i;
				// printf("(*sta)->ra: %d\n", (*sta)->ra);
				// printf("(*stb)->rb: %d\n\n\n\n", (*stb)->rb);
				// printf("my value for tmp_ra_cheap is: %d\nmy value for tmp_rb_cheap is: %d\n\n\n", tmp_ra_cheap, tmp_rb_cheap);
				move_it(sta, stb, tmp_ra_cheap, tmp_rb_cheap);
				// *sta = sta_save;
			}
			else
			{
				(*sta) = (*sta)->next;	
				i++;	
			}
			tmp_ra_cheap = 0;
			tmp_rb_cheap = 0;
		}
		(*sta) = sta_save;
		tmp_size--;
	}
}
*/