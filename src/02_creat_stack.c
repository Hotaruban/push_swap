/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:23:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 01:44:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
				error_double(array, stack);
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
	tmp = ft_atol(array[i]);
	if (tmp > INT_MAX || tmp < INT_MIN)
		error_integers(array, stack);
	stack->num = tmp;
	i++;
	while (array[i])
	{
		tmp = ft_atol(array[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_integers(array, stack);
		lstadd_back(&stack, lstnew(tmp));
		if (stack->next == NULL)
		{
			free_2d_array(array);
			lstclear(&stack);
			error_malloc(NULL);
		}
		i++;
	}
	return (stack);
}

t_stack	*creat_stack(char **tab)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		free_2d_array(tab);
		error_malloc(NULL);
	}
	stack = fill_data_stack(tab, stack);
	check_double(tab, stack);
	free_2d_array(tab);
	if (check_sorted(stack) == 1)
	{
		printf("GO HERE\n");
		lstclear(&stack);
		exit(0);
	}
	return (stack);
}
