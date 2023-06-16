/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:20:26 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 23:58:54 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_position(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_stack	*tmp_a;
	int		i;
	int		tmp;

	tmp_a = stack_a;
	tmp = len;
	while (stack_b)
	{
		i = 0;
		while (stack_a)
		{
			if ((stack_a->ind - stack_b->ind) > 0
				&& tmp > (stack_a->ind - stack_b->ind))
			{
				tmp = stack_a->ind - stack_b->ind;
				stack_b->target = i;
			}
			stack_a = stack_a->next;
			i++;
		}
		stack_a = tmp_a;
		stack_b = stack_b->next;
		tmp = len;
	}
}

void	set_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_index(t_stack *stack, int len)
{
	t_stack	*head;
	t_stack	*ptr_index;
	int		i;

	head = stack;
	ptr_index = head;
	i = 1;
	while (len >= i)
	{
		while (head->next != NULL)
		{
			if (head->ind == 0 && head->num <= ptr_index->num)
				ptr_index = head;
			head = head->next;
		}
		if (head->ind == 0 && head->num <= ptr_index->num)
			ptr_index = head;
		ptr_index->ind = i;
		head = stack;
		while (head->ind != 0 && i != len)
			head = head->next;
		i++;
		ptr_index = head;
	}
}

void	set_data(t_stack **stack_a, t_stack **stack_b, int len)
{
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_position(*stack_a, *stack_b, len);
}
