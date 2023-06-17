/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:49:11 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 23:58:51 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_rrr(t_stack **s_a, t_stack **s_b, int *act_a, int *act_b)
{
	while (*act_a < 0 && *act_b < 0)
	{
		(*act_a)++;
		(*act_b)++;
		do_rrr(s_a, s_b);
	}
}

static void	sort_rr(t_stack **s_a, t_stack **s_b, int *act_a, int *act_b)
{
	while (*act_a > 0 && *act_b > 0)
	{
		(*act_a)--;
		(*act_b)--;
		do_rr(s_a, s_b);
	}
}

static void	sort_ra_rra(t_stack **stack, int *act_a)
{
	while (*act_a)
	{
		if (*act_a > 0)
		{
			(*act_a)--;
			do_ra(stack);
		}
		else if (*act_a < 0)
		{
			(*act_a)++;
			do_rra(stack);
		}
	}
}

static void	sort_rb_rrb(t_stack **stack, int *act_b)
{
	while (*act_b)
	{
		if (*act_b > 0)
		{
			(*act_b)--;
			do_rb(stack);
		}
		else if (*act_b < 0)
		{
			(*act_b)++;
			do_rrb(stack);
		}
	}
}

void	sort_stack(t_stack **s_a, t_stack **s_b, int act_a, int act_b)
{
	if (act_a < 0 && act_b < 0)
		sort_rrr(s_a, s_b, &act_a, &act_b);
	else if (act_a > 0 && act_b > 0)
		sort_rr(s_a, s_b, &act_a, &act_b);
	sort_ra_rra(s_a, &act_a);
	sort_rb_rrb(s_b, &act_b);
	do_pa(s_b, s_a);
}
