/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:48:58 by jhurpy            #+#    #+#             */
/*   Updated: 2023/09/28 20:41:40 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	long			num;
	struct s_stack	*next;
}				t_stack;

typedef struct s_actions
{
	char				*action;
	struct s_actions	*next;
}				t_actions;

int		check_sorted_bonus(t_stack *stack);
void	sorting(t_stack *stack_a, t_stack *stack_b, t_actions *actions);
void	swap(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	push(t_stack *s_start, t_stack *s_end);

int		check_action(char *action);
void	free_list_actions(t_actions *actions);
int		create_actions(t_actions *actions);

void	lstadd_back_bonus(t_stack **lst, t_stack *new);
t_stack	*lstnew_bonus(int num);
t_stack	*creat_stack_bonus(char **tab);
char	**join_split_bonus(int ac, char **av);
void	sorting(t_stack *stack_a, t_stack *stack_b, t_actions *actions);

void	error_malloc_bonus(char *array);
void	error_integers_bonus(char **array, t_stack *stack);
void	error_double_bonus(char **array, t_stack *stack);
void	error_digit_bonus(char **array);

void	free_2d_array_bonus(char **array);
void	free_stack_bonus(t_stack *stack);
void	lstclear_bonus(t_stack **lst);


#endif
