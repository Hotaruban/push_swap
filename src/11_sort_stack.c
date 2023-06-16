/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:49:11 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 04:46:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while ((*stack_b)->act_a < i || (*stack_b)->act_b < i)
	{
		actions_rra_rrb(stack_a);
		actions_rra_rrb(stack_b);
		ft_putstr_fd("rrr\n", 1);
		i--;
	}
	while ((*stack_b)->act_a < i)
	{
		actions_rra_rrb(stack_a);
		ft_putstr_fd("rra\n", 1);
		i--;
	}
	while ((*stack_b)->act_b < i)
	{
		actions_rra_rrb(stack_b);
		ft_putstr_fd("rrb\n", 1);
		i--;
	}
	actions_pa_pb(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

static void	sort_rr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while ((*stack_b)->act_a > i || (*stack_b)->act_b > i)
	{
		actions_ra_rb(stack_a);
		actions_ra_rb(stack_b);
		ft_putstr_fd("rr\n", 1);
		i++;
	}
	while ((*stack_b)->act_a > i)
	{
		actions_ra_rb(stack_a);
		ft_putstr_fd("ra\n", 1);
		i++;
	}
	while ((*stack_b)->act_b > i)
	{
		actions_ra_rb(stack_b);
		ft_putstr_fd("rb\n", 1);
		i++;
	}
	actions_pa_pb(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

static void	sort_mix2(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->act_a-- > 0)
	{
		actions_ra_rb(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	while ((*stack_b)->act_b++ < 0)
	{
		actions_rra_rrb(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}

static void	sort_mix(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->act_a < 0 || (*stack_b)->act_b > 0)
	{
		while ((*stack_b)->act_a++ < 0)
		{
			actions_rra_rrb(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
		while ((*stack_b)->act_b-- > 0)
		{
			actions_ra_rb(stack_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
	else
		sort_mix2(stack_a, stack_b);
	actions_pa_pb(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
	while ((*stack_b)->nb_act != cheapest)
	{
		stack_b = &(*stack_b)->next;
	}
	if ((*stack_b)->act_a < 0 && (*stack_b)->act_b < 0)
		sort_rrr(stack_a, stack_b);
	else if ((*stack_b)->act_a > 0 && (*stack_b)->act_b > 0)
		sort_rr(stack_a, stack_b);
	else
		sort_mix(stack_a, stack_b);
}
