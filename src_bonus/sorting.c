/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:02:53 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 21:50:56 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	do_stack(t_stack *stack, t_actions *actions)
{
	if (ft_strncmp(actions->action, "sa", 3) == 0
		|| ft_strncmp(actions->action, "sb", 3) == 0)
		swap(stack);
	else if (ft_strncmp(actions->action, "ra", 3) == 0
		|| ft_strncmp(actions->action, "rb", 3) == 0)
		rotate(stack);
	else if (ft_strncmp(actions->action, "rra", 4) == 0
		|| ft_strncmp(actions->action, "rrb", 4) == 0)
		reverse_rotate(stack);
}

static void	do_stack_ab(t_stack *stack_a, t_stack *stack_b, t_actions *actions)
{
	if (ft_strncmp(actions->action, "ss", 3))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(actions->action, "rr", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strncmp(actions->action, "rrr", 4))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else if (ft_strncmp(actions->action, "pa", 3))
		push(stack_b, stack_a);
	else if (ft_strncmp(actions->action, "pb", 3))
		push(stack_a, stack_b);
}

void	sorting(t_stack *stack_a, t_stack *stack_b, t_actions *actions)
{
	t_actions	*tmp;

	tmp = actions;
	while (tmp)
	{
		if (ft_strncmp(tmp->action, "sa", 3)
			|| ft_strncmp(tmp->action, "pa", 3)
			|| ft_strncmp(tmp->action, "ra", 3)
			|| ft_strncmp(tmp->action, "rra", 4))
			do_stack(stack_a, actions);
		else if (ft_strncmp(tmp->action, "sb", 3)
			|| ft_strncmp(tmp->action, "pb", 3)
			|| ft_strncmp(tmp->action, "rb", 3)
			|| ft_strncmp(tmp->action, "rrb", 4))
			do_stack(stack_b, actions);
		else if (ft_strncmp(tmp->action, "ss", 3)
			|| ft_strncmp(tmp->action, "rr", 3)
			|| ft_strncmp(tmp->action, "rrr", 4))
			do_stack_ab(stack_a, stack_b, actions);
		tmp = tmp->next;
	}
}
