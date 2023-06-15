/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:19:33 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 03:03:03 by jhurpy           ###   ########.fr       */
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
		sort_small(&stack_a, len_list);
	else
		sort_big(&stack_a, &stack_b, len_list);

	// START OF REMOVE
	printf("List _a_\n");
	while (stack_a)
	{
		//printf("-- num_a %d -- \n", stack_a->num);
		printf("-- ind %d pos %d target %d-- \n", stack_a->ind, stack_a->pos, stack_a->target);
		stack_a = stack_a->next;
	}
	printf("List _b_\n");
	while (stack_b)
	{
		//printf("-- num_b %d -- \n", stack_b->num);
		printf("-- ind %d pos %d target %d-- \n", stack_b->ind, stack_b->pos, stack_b->target);
		stack_b = stack_b->next;
	}
	// END OF REMOVE

	lstclear(&stack_a);
	return (0);
}
