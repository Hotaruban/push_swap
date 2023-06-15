/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:35 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 03:28:55 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->ind > tmp->next->ind)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
		{
			actions_ra_rb(stack);
			ft_putstr_fd("ra\n", 1);
		}
		else if ((tmp->ind > tmp2->ind) && (tmp->ind > (*stack)->ind))
		{
			actions_rra_rrb(stack);
			ft_putstr_fd("rra\n", 1);
		}
		else
		{
			action_sa_sb(stack);
			ft_putstr_fd("sa\n", 1);
		}
	}
}

void	sort_small(t_stack **stack_a, int len)
{
	if (len == 2)
	{
		action_sa_sb(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else
		sort_three(stack_a);
}
