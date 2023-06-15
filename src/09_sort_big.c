/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 00:36:11 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 03:10:34 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_b(t_stack **stack, int len)
{
	if ((*stack)->ind <= (len / 2))
	{
		actions_ra_rb(stack);
		ft_putstr_fd("rb\n", 1);
	}
}

static void	push_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	while (lst_size(*stack_a) > 3)
	{
		while ((*stack_a)->ind > (len - 3))
		{
			actions_ra_rb(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
		actions_pa_pb(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
		if (lst_size(*stack_b) > 1)
			sort_b(stack_b, len);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int len)
{
	push_b(stack_a, stack_b, len);
	sort_small(stack_a, 3);
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_position(*stack_a, *stack_b);
}
