/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:20:26 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/11 02:36:56 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
