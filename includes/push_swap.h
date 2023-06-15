/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:02:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/16 03:46:58 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>

# include <stdio.h> /// to remove after all test

typedef struct s_stack
{
	int				num;
	int				ind;
	int				pos;
	int				target;
	struct s_stack	*next;
}				t_stack;

/*
Function for free and exit
*/
void	error_malloc(char *array);
void	error_digit(char **array);
void	error_integers(char **array, t_stack *stack);
void	error_double(char **array, t_stack *stack);
void	free_2d_array(char **array);
void	free_stack(t_stack *stack);
void	lstclear(t_stack **lst);

/*
Function take the input and create a list of integers
*/
int		main(int ac, char **av);
char	**join_split(int ac, char **av);
t_stack	*creat_stack(char **tab);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int num);
int		lst_size(t_stack *stack);

/*
Function will sort the list
*/
void	sort_small(t_stack **stack_a, int len);
void	sort_big(t_stack **stack_a, t_stack **stack_b, int len);
void	push_a(t_stack **stack_a, t_stack **stack_b, int len);
void	set_data(t_stack **stack_a, t_stack **stack_b);
void	set_index(t_stack *stack, int len);
void	set_position(t_stack *stack);
void	set_target_position(t_stack *stack_a, t_stack *stack_b);
/*
Functions/actions for swap the nodes in stack.
*/
void	action_sa_sb(t_stack **stack);
void	actions_ra_rb(t_stack **stack);
void	actions_rra_rrb(t_stack **stack);
void	actions_pa_pb(t_stack **s_start, t_stack **s_end);

#endif
