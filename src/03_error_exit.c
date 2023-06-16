/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:31:56 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 05:01:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_malloc(char *array)
{
	free(array);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_digit(char **array)
{
	free_2d_array(array);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_integers(char **array, t_stack *stack)
{
	free_2d_array(array);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_double(char **array, t_stack *stack)
{
	free_2d_array(array);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
