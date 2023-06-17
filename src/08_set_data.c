/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:20:26 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 23:59:19 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	act_a_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = lst_size(*stack_a);
	size_b = lst_size(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->act_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->act_b = (size_b - tmp_b->pos) * -1;
		tmp_b->act_a = tmp_b->target;
		if (tmp_b->target > (size_a / 2))
			tmp_b->act_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

static int	get_target(t_stack **stack_a, int b_ind, int t_ind, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->ind > b_ind && tmp_a->ind < t_ind)
		{
			t_ind = tmp_a->ind;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_pos != t_ind)
		return (target_pos);
	tmp_a = (*stack_a);
	while (tmp_a)
	{
		if (tmp_a->ind < t_ind)
		{
			t_ind = tmp_a->ind;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

static void	set_target_position(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = *stack_b;
	target_pos = 0;
	while (tmp)
	{
		target_pos = get_target(stack_a, tmp->ind, len, target_pos);
		tmp->target = target_pos;
		tmp = tmp->next;
	}
}

static void	set_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_data(t_stack **stack_a, t_stack **stack_b, int len)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_position(stack_a, stack_b, len);
	act_a_b(stack_a, stack_b);
}
