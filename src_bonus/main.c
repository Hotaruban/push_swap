/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:38:49 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 22:03:42 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	empty_string(int ac, char **av)
{
	int	i;
	int	count;
	int	error;

	i = 0;
	count = 0;
	error = 0;
	while (ac > ++i)
	{
		if (ft_strlen(av[i]) == 0)
			error++;
		else
			count++;
	}
	if ((error > 0 && count > 0) || (ac >= 2 && error > 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	else if (error > 0 && count == 0)
		exit (0);
	else
		return ;
}

static void	check_digit(int ac, char **av)
{
	int		i;
	int		j;
	int		space;

	i = 0;
	j = 0;
	space = 0;
	while (ac > ++i)
	{
		while (ft_isspace(av[i][j]) && av[i][j])
		{
			space++;
			j++;
			if (av[i][j] == '\0' && j == space)
			{
				ft_putstr_fd("Error\n", 2);
				exit (0);
			}
		}
		i++;
	}
	return ;
}

static char	**verif_and_split(int ac, char **av)
{
	char	**split;

	empty_string(ac, av);
	check_digit(ac, av);
	split = join_split_bonus(ac, av);
	return (split);
}

int	main(int ac, char **av)
{
	char		**split;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_actions	*actions;

	if (ac < 2)
		return (0);
	split = verif_and_split(ac, av);
	stack_a = creat_stack_bonus(split);
	stack_b = NULL;
	actions = NULL;
	if (create_actions(actions) == 1)
	{
		lstclear_bonus(&stack_a);
		free_list_actions(actions);
		return (0);
	}
	ft_putendl_fd("Actions:", 2);
	ft_putendl_fd(actions->action, 2);
	sorting(stack_a, stack_b, actions);
	if (check_sorted_bonus(stack_a) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	lstclear_bonus(&stack_a);
	free_list_actions(actions);
	return (0);
}
