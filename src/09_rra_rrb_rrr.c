/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:43:01 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 20:57:19 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	actions_rra_rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_end;

	tmp = *stack;
	while ((*stack)->next != NULL)
	{
		tmp_end = *stack;
		*stack = (*stack)->next;
	}
	(*stack)->next = tmp;
	tmp_end->next = NULL;
}

void	do_rra(t_stack **stack)
{
	actions_rra_rrb(stack);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack **stack)
{
	actions_rra_rrb(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	actions_rra_rrb(stack_a);
	actions_rra_rrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
