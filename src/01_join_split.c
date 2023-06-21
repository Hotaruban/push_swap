/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_join_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:03:59 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/22 00:23:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
The file will check the input, join the arguments and split them into an array
then check if the input is valid and return the array.
*/

static int	check_split(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[++j])
	{
		i = 0;
		if (ft_strlen(str[j]) > 11)
			return (1);
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		if (!ft_isdigit(str[j][i]))
			return (1);
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i++]))
				return (1);
		}
	}
	return (0);
}

static char	*join_argv(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	if (str == NULL)
		error_malloc(NULL);
	while (++i < ac)
	{
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		if (str == NULL)
			error_malloc(tmp);
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		if (str == NULL)
			error_malloc(tmp);
		free(tmp);
	}
	return (str);
}

char	**join_split(int ac, char **av)
{
	char	*str;
	char	**tab;

	str = NULL;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (tab == NULL)
			error_malloc(NULL);
	}
	else
	{
		str = join_argv(ac, av);
		tab = ft_split(str, ' ');
		if (tab == NULL)
			error_malloc(str);
		free(str);
	}
	if (check_split(tab) == 1)
		error_digit(tab);
	return (tab);
}
