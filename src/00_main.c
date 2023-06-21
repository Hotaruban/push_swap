/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:19:33 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/22 00:23:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
The set_index function, set an index to every numbers to make the manipulation
easier.
*/

static void	set_index(t_stack *stack, int len)
{
	t_stack	*head;
	t_stack	*ptr_index;
	int		i;

	head = stack;
	ptr_index = head;
	i = 1;
	while (len >= i)
	{
		while (head->next != NULL)
		{
			if (head->ind == 0 && head->num <= ptr_index->num)
				ptr_index = head;
			head = head->next;
		}
		if (head->ind == 0 && head->num <= ptr_index->num)
			ptr_index = head;
		ptr_index->ind = i;
		head = stack;
		while (head->ind != 0 && i != len)
			head = head->next;
		i++;
		ptr_index = head;
	}
}

static void	empty_string(int ac, char **av)
{
	int	i;
	int	count;
	int	error;

	i = 0;
	count = 0;
	error = 0;
	while (ac > ++i)
	{
		if (ft_strlen(av[i]) == 0)
			error++;
		else
			count++;
	}
	if (error > 0 && count > 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	else if (error > 0 && count == 0)
		exit (0);
	else
		return ;
}

static int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ac > ++j)
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		if (!ft_isdigit(av[j][i]))
			return (1);
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i++]))
				return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**split;
	int		len_list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	empty_string(ac, av);
	if (check_digit(ac, av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	split = join_split(ac, av);
	stack_a = creat_stack(split);
	len_list = lst_size(stack_a);
	set_index(stack_a, len_list);
	stack_b = NULL;
	if (len_list <= 3)
		sort_small(&stack_a, len_list);
	else
		sort_big(&stack_a, &stack_b, len_list);
	lstclear(&stack_a);
	return (0);
}

/*

	// START OF REMOVE
	printf("List _a_\n");
	while (stack_a)
	{
		//printf("-- num_a %d -- \n", stack_a->num);
		printf("-- ind %d	pos %d	target %d-- \n",
			stack_a->ind, stack_a->pos, stack_a->target);
		stack_a = stack_a->next;
	}
	printf("List _b_\n");
	while (stack_b)
	{
		//printf("-- num_b %d -- \n", stack_b->num);
		printf("-- ind %d	pos %d	target %d	-- cost_a %d	-- cost_b %d --\n",
			stack_b->ind, stack_b->pos, stack_b->target,
			stack_b->act_a, stack_b->act_b);
		stack_b = stack_b->next;
	}
	// END OF REMOVE

*/
