/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:34:48 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 04:44:35 by jhurpy           ###   ########.fr       */
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

static void	act_a_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	size_a = lst_size(stack_a);
	tmp = stack_b;
	while (stack_b)
	{
		if (stack_b->target > (size_a / 2))
			stack_b->act_a = stack_b->target - size_a;
		else
			stack_b->act_a = stack_b->target;
		stack_b = stack_b->next;
	}
	size_b = lst_size(stack_b);
	stack_b = tmp;
	while (stack_b)
	{
		if (stack_b->pos > (size_b / 2))
			stack_b->act_b = stack_b->pos - size_b;
		else
			stack_b->act_b = stack_b->pos;
		stack_b = stack_b->next;
	}
}

static int	find_cheapest_action(t_stack *stack_b, int len)
{
	t_stack	*tmp;
	int		cheapest;

	tmp = stack_b;
	while (stack_b)
	{
		stack_b->nb_act = ft_absolut(stack_b->act_a)
			+ ft_absolut(stack_b->act_b);
		stack_b = stack_b->next;
	}
	stack_b = tmp;
	cheapest = len;
	while (stack_b)
	{
		if (stack_b->nb_act < cheapest)
			cheapest = stack_b->nb_act;
		stack_b = stack_b->next;
	}
	return (cheapest);
}

void	push_a(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	cheapest;

	while (lst_size(*stack_a) < len)
	{
		set_data(stack_a, stack_b, len);
		act_a_b(*stack_a, *stack_b);
		cheapest = find_cheapest_action(*stack_b, len);
		sort_stack(stack_a, stack_b, cheapest);
	}
	set_data(stack_a, stack_b, len);
	while (check_sorted(*stack_a) == 0)
	{
		actions_rra_rrb(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}
