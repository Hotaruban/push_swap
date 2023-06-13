/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:19:33 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/14 00:05:55 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**split;
	int		len_list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	split = join_split(ac, av);
	stack_a = creat_stack(split);
	len_list = lst_size(stack_a);
	set_index(stack_a, len_list);
	if (len_list <= 3)
		sort_small(stack_a, stack_b, len_list);
	lstclear(&stack_a);
	return (0);
}
