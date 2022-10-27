/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:54:30 by oscobou           #+#    #+#             */
/*   Updated: 2022/10/27 20:02:02 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	ft_sa(stack **sta)
{
	stack	*save;
	stack	*tmp;

	if (!*sta || (*sta)->next == NULL)
		return ;
	write(1, "sa\n", 3);
	tmp = (*sta);
	(*sta) = (*sta)->next;
	save = (*sta)->next;
	(*sta)->next = tmp;
	tmp->next = save;
}

void	ft_pa(stack **sta, stack **stb)
{
	stack	*tmp;

	if (*stb == NULL)
		return ;
	write(1, "pa\n", 3);
	if (*sta == NULL)
	{
		(*sta) = (*stb);
		(*stb) = (*stb)->next;
		(*sta)->next = NULL;
		return ;
	}
	tmp = (*stb)->next;
	(*stb)->next = (*sta);
	(*sta) = (*stb);
	(*stb) = tmp;
}

void	ft_ra(stack **sta)
{
	stack	*save_a;
	stack	*tmp;

	if (!(*sta))
		return ;
	write(1, "ra\n", 3);
	save_a = (*sta);
	tmp = (*sta)->next;
	while ((*sta)->next != NULL)
		(*sta) = (*sta)->next;
	(*sta)->next = save_a;
	save_a->next = NULL;
	(*sta) = tmp;
}

void	ft_rra(stack **sta)
{
	stack	*save_bottom;
	stack	*tmp1;
	stack	*tmp;

	if (!(*sta))
		return ;
	write(1, "rra\n", 4);
	tmp1 = (*sta);
	tmp = *sta;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	save_bottom = tmp->next;
	tmp->next = (NULL);
	(*sta) = save_bottom;
	(*sta)->next = tmp1;
}
