/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:58:54 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 20:28:48 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	check_double(char **array, t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->num == tmp2->num)
				error_double_bonus(array, stack);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	(void)array;
}

static t_stack	*fill_data_stack(char **array, t_stack *stack)
{
	int		i;
	long	tmp;

	i = 0;
	while (array[i])
	{
		tmp = ft_atol(array[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_integers_bonus(array, stack);
		lstadd_back_bonus(&stack, lstnew_bonus(tmp));
		if (stack == NULL)
		{
			free_2d_array_bonus(array);
			lstclear_bonus(&stack);
			error_malloc_bonus(NULL);
		}
		i++;
	}
	return (stack);
}

t_stack	*creat_stack_bonus(char **tab)
{
	t_stack	*stack;

	stack = NULL;
	stack = fill_data_stack(tab, stack);
	check_double(tab, stack);
	free_2d_array_bonus(tab);
	if (check_sorted_bonus(stack) == 1)
	{
		lstclear_bonus(&stack);
		exit(0);
	}
	return (stack);
}
