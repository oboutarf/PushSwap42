/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:04:30 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/29 23:46:54 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

t_stack	*create_new_stack(void)
{
	return (NULL);
}

int	ft_atoi(char *nptr)
{
	int		mns;
	int		num;
	int		i;

	i = 0;
	num = 0;
	mns = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		mns = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * mns);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int	ft_isdup(t_stack *sta)
{
	t_stack		*sta_comp;

	sta_comp = sta;
	while (sta)
	{
		sta_comp = sta->next;
		while (sta_comp)
		{
			if (sta->value == sta_comp->value)
				return (-1);
			sta_comp = sta_comp->next;
		}
		sta = sta->next;
	}
	return (0);
} */


int	ft_isdup(char **av)
{
	int		comparing;
	int		to_comp;

	to_comp = 1;
	comparing = 0;
	while (av[to_comp])
	{
		comparing = to_comp + 1;
		while (av[comparing])
		{
			if (ft_atoi(av[to_comp]) == ft_atoi(av[comparing]))
				return (-1);
			comparing++;
		}
		to_comp++;
	}
	return (0);
}