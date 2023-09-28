/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:34:07 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 20:39:05 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
List of function to free the memory.
*/

void	free_2d_array_bonus(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack_bonus(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	lstclear_bonus(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*node;

	temp = *lst;
	if (lst == NULL)
		return ;
	while (temp != NULL)
	{
		node = temp->next;
		free(temp);
		temp = node;
	}
	*lst = NULL;
}
