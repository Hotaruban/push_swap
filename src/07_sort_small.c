/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:35 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/11 02:57:21 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_2(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	if (stack->ind == 1 && tmp->ind == 3)
	{
		action_sa_sb(stack);
		ft_putstr_fd("sa\n", 1);
		actions_ra_rb(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		action_sa_sb(stack);
		ft_putstr_fd("sa\n", 1);
		actions_rra_rrb(stack);
		ft_putstr_fd("rra\n", 1);
	}
}

static void	sort_three(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	if (stack->ind == 2 && tmp->ind == 1)
	{
		action_sa_sb(stack);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack->ind == 3 && tmp->ind == 1)
	{
		actions_ra_rb(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else if (stack->ind == 2 && tmp->ind == 3)
	{
		actions_rra_rrb(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else
		sort_three_2(stack);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 2)
	{
		action_sa_sb(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (len == 3)
	{
		sort_three(stack_a);
	}
	else
		return ;
	(void)stack_b;
}
