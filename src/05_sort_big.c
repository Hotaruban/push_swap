/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 00:36:11 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/18 01:39:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_cheap(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp;
	int		cheapest;
	int		act_a;
	int		act_b;

	tmp = *stack_b;
	cheapest = len;
	while (tmp)
	{
		if ((ft_absolut(tmp->act_a) + ft_absolut(tmp->act_b))
			< ft_absolut(cheapest))
		{
			cheapest = ft_absolut(tmp->act_b) + ft_absolut(tmp->act_a);
			act_a = tmp->act_a;
			act_b = tmp->act_b;
		}
		tmp = tmp->next;
	}
	sort_stack(stack_a, stack_b, act_a, act_b);
}

static void	push_a(t_stack **stack_a, t_stack **stack_b, int len)
{
	while (lst_size(*stack_a) < len)
	{
		set_data(stack_a, stack_b, len);
		move_cheap(stack_a, stack_b, len);
	}
}

static void	push_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	while (lst_size(*stack_a) > 3)
	{
		while ((*stack_a)->ind > (len - 3))
			do_ra(stack_a);
		do_pb(stack_a, stack_b);
		if (lst_size(*stack_b) > 1)
		{
			if ((*stack_b)->ind <= (len / 2)
				&& (*stack_b)->next->ind >= (len / 2))
				do_rb(stack_b);
		}
	}
	sort_small(stack_a, 3);
	set_data(stack_a, stack_b, len);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int len)
{
	push_b(stack_a, stack_b, len);
	push_a(stack_a, stack_b, len);
	while (check_sorted(*stack_a) == 0)
		do_rra(stack_a);
}
