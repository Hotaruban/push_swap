/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:19:33 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/10 00:14:09 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**split;
	int		len_list;
	t_stack	*stack_a;

	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	split = join_split(ac, av);
	stack_a = creat_stack(split);
	len_list = lst_size(stack_a);
	lstclear(&stack_a);
	(void)stack_a;	// to remove
	(void)len_list;	// to remove
	return (0);
}
