/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:43:05 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 20:58:00 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	actions_pa_pb(t_stack **s_start, t_stack **s_end)
{
	t_stack	*tmp;

	tmp = (*s_start)->next;
	(*s_start)->next = *s_end;
	*s_end = *s_start;
	*s_start = tmp;
}

void	do_pa(t_stack **stack_b, t_stack **stack_a)
{
	actions_pa_pb(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	actions_pa_pb(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
