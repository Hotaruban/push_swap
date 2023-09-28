/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:15:51 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 22:01:04 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_list_actions(t_actions *actions)
{
	t_actions	*tmp;

	while (actions)
	{
		tmp = actions;
		actions = actions->next;
		free(tmp->action);
		free(tmp);
	}
	actions = NULL;
}

int	create_actions(t_actions *actions)
{
	t_actions	*new;
	char		*line;
	char		*tmp;

	actions = (t_actions *)malloc(sizeof(t_actions));
	if (!actions)
		return (1);
	new = actions;
	line = get_next_line(0);
	while (line)
	{
		tmp = line;
		new->action = ft_strtrim(tmp, "\n");
		free(line);
		if (check_action(new->action) == 1)
			return (1);
		new->next = (t_actions *)malloc(sizeof(t_actions));
		if (!new->next)
			return (1);
		line = get_next_line(0);
		new = new->next;
	}
	free(line);
	new->next = NULL;
	return (0);
}
