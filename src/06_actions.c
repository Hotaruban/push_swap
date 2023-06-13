/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:34:18 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/14 00:06:48 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
The different functions/actions used to swap the nodes in the stack.
*/

void	action_sa_sb(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	stack = tmp;
}

void	actions_ra_rb(t_stack *stack)
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

void	actions_rra_rrb(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp_end;

	tmp = stack;
	while (stack->next != NULL)
		stack = stack->next;
	tmp_end = stack;
	stack = NULL;
	tmp_end->next = tmp;
	stack = tmp_end;
}

void	actions_pa_pb(t_stack *s_start, t_stack *s_end)
/*
Have to handle the memory allocation et dellocation from one list to an other apparently.
*/
{
	t_stack	*tmp;

	tmp = s_start->next;
	s_start->next = s_end;
	s_end = s_start;
	s_start = tmp;
}