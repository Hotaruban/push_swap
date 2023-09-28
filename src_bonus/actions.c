/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:35:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 14:41:50 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	stack = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp_end;

	tmp = stack;
	while (stack->next != NULL)
	{
		tmp_end = stack;
		stack = stack->next;
	}
	stack->next = tmp;
	tmp_end->next = NULL;
}

void	rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp_head;

	tmp = stack->next;
	tmp_head = stack;
	while (stack->next != NULL)
		stack = stack->next;
	tmp_head->next = NULL;
	stack->next = tmp_head;
	stack = tmp;
}

void	push(t_stack *s_start, t_stack *s_end)
{
	t_stack	*tmp;

	tmp = s_start->next;
	s_start->next = s_end;
	s_end = s_start;
	s_start = tmp;
}
