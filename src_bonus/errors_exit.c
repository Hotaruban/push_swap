/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:01:31 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 20:41:04 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	error_malloc_bonus(char *array)
{
	free(array);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_integers_bonus(char **array, t_stack *stack)
{
	free_2d_array_bonus(array);
	free_stack_bonus(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_digit_bonus(char **array)
{
	free_2d_array_bonus(array);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_double_bonus(char **array, t_stack *stack)
{
	free_2d_array_bonus(array);
	free_stack_bonus(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
