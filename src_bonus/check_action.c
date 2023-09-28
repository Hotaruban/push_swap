/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:24:43 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 21:52:55 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_action(char *action)
{
	if (ft_strncmp(action, "sa", 3) && ft_strncmp(action, "sb", 3)
		&& ft_strncmp(action, "ss", 3) && ft_strncmp(action, "pa", 3)
		&& ft_strncmp(action, "pb", 3) && ft_strncmp(action, "ra", 3)
		&& ft_strncmp(action, "rb", 3) && ft_strncmp(action, "rr", 3)
		&& ft_strncmp(action, "rra", 4) && ft_strncmp(action, "rrb", 4)
		&& ft_strncmp(action, "rrr", 4))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
