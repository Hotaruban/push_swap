/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_link_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:44:21 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/09 16:45:08 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	node = *lst;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
}

t_stack	*lstnew(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node != NULL)
	{
		new_node->num = num;
		new_node->next = NULL;
	}
	return (new_node);
}
