/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:35 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 21:47:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	action_sa_sb(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	ft_putstr_fd("sa\n", 1);
}

static void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	while (check_sorted(*stack) == 0)
	{
		tmp = (*stack)->next;
		tmp2 = tmp->next;
		if (((*stack)->ind > tmp->ind) && ((*stack)->ind > tmp2->ind))
			do_ra(stack);
		else if ((tmp->ind > tmp2->ind) && (tmp->ind > (*stack)->ind))
			do_rra(stack);
		else
			action_sa_sb(stack);
	}
}

void	sort_small(t_stack **stack_a, int len)
{
	if (len == 2)
		action_sa_sb(stack_a);
	else
		sort_three(stack_a);
}
