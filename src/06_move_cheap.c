/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_move_cheap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:34:48 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 23:56:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_cheap(t_stack **stack_a, t_stack **stack_b, int len)
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
