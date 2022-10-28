/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:59:53 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/28 19:57:16 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

void	ft_sb(t_stack **stb)
{
	t_stack	*save;
	t_stack	*tmp;

	if (!*stb || (*stb)->next == NULL)
		return ;
	write(1, "sb\n", 3);
	tmp = (*stb);
	(*stb) = (*stb)->next;
	save = (*stb)->next;
	(*stb)->next = tmp;
	tmp->next = save;
	ft_index(*stb);
}

void	ft_pb(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	if (*sta == NULL)
		return ;
	write(1, "pb\n", 3);
	if (*stb == NULL)
	{
		(*stb) = (*sta);
		(*sta) = (*sta)->next;
		(*stb)->next = NULL;
		return ;
	}
	tmp = (*sta)->next;
	(*sta)->next = (*stb);
	(*stb) = (*sta);
	(*sta) = tmp;
	ft_index(*stb);
}

void	ft_rb(t_stack **stb)
{
	t_stack	*save_b;
	t_stack	*tmp;

	if (!(*stb))
		return ;
	write(1, "rb\n", 3);
	save_b = (*stb);
	tmp = (*stb)->next;
	while ((*stb)->next != NULL)
		(*stb) = (*stb)->next;
	(*stb)->next = save_b;
	save_b->next = NULL;
	(*stb) = tmp;
	ft_index(*stb);
}

void	ft_rrb(t_stack **stb)
{
	t_stack	**stb_save;
	t_stack	*save_bottom;
	t_stack	*tmp;

	if (!(*stb))
		return ;
	write(1, "rrb\n", 4);
	stb_save = stb;
	tmp = (*stb);
	while ((*stb_save)->next->next != NULL)
		(*stb_save) = (*stb_save)->next;
	save_bottom = (*stb_save)->next;
	(*stb_save)->next = (NULL);
	(*stb) = save_bottom;
	(*stb)->next = tmp;
	ft_index(*stb);
}
