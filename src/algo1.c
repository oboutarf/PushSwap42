/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:38:32 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/05 19:19:23 by oboutarf         ###   ########.fr       */
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

void	search_elem_back(stack **sta, stack stb)
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

void	search_elem(stack **sta, stack stb)
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

void	choose_which_way(stack **sta, stack stb)
{
	stack *last_a;
	
	last_a = *sta;
	while (last_a->next)
		last_a = last_a->next;
	if (stb.value < last_a->value)
		search_elem_back(sta, stb);
	else
		search_elem(sta, stb);
}

void	what_move(stack *sta, stack *stb)
{
	while (stb->next != NULL)
	{
		choose_which_way(&sta, *stb);
		ft_pa(&sta, &stb);
	}
}

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
	ft_rra(sta);
	what_move(*sta, *stb);
	// start_max(*sta, stb, tmp_size);//
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

void	move_now(stack **sta, stack **stb, int tmp_ra_cheap, int tmp_rb_cheap)
{
	if (tmp_ra_cheap == 0 && tmp_rb_cheap == 0)
		ft_pa(sta, stb);
	if (tmp_ra_cheap > 0)
	{
		printf("YO");
		while (tmp_ra_cheap > 0)
		{
			tmp_ra_cheap--;
			ft_ra(sta);
		}
		ft_pa(sta, stb);
	}
}

void	what_move(stack *sta, stack *stb)
{
	int		rest_b = 0;
	stack	*last_a;
	// stack	*tmp_a;
	// int		i = 0;

	while (stb->next != NULL)
	{
		rest_b = get_stacklen(stb);
		while (rest_b + 1 > 0)
		{
			last_a = sta;
			while (last_a->next)
				last_a = last_a->next;
			give_ra_rra(sta);
			give_rb_rrb(stb);
			if (stb->value <= sta->value && stb->value >= last_a->value)
			{
				move_now(&sta, &stb, sta->ra, 0);
				rest_b--;
			}
			else
				ft_ra(&sta);
		}
		// i = 0;
	}
}










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