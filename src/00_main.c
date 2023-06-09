/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:19:33 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/09 18:22:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**split;
	t_stack	*stack_a;

	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	split = join_split(ac, av);
	stack_a = creat_stack(split);
	(void)stack_a;
	return (0);
}
