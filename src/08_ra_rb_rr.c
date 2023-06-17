/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:42:45 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 18:47:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	actions_ra_rb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_head;

	tmp = (*stack)->next;
	tmp_head = *stack;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	tmp_head->next = NULL;
	(*stack)->next = tmp_head;
	*stack = tmp;
}

void	do_ra(t_stack **stack)
{
	actions_ra_rb(stack);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_stack **stack)
{
	actions_ra_rb(stack);
	ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	actions_ra_rb(stack_a);
	actions_ra_rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
