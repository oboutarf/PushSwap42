/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:23:39 by oboutarf          #+#    #+#             */
/*   Updated: 2022/10/29 23:19:50 by oboutarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/push_swap.h"

int	check_sorted(char **av, int ac)
{
	int		compare;

	compare = 1;
	while (ac - 1 > 0)
	{
		if (ft_atoi(av[compare]) > ft_atoi(av[compare + 1]))
			return (0);
		compare++;
		ac--;
	}
	return (-1);
}