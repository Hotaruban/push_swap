/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:02:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/18 01:40:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				ind;
	int				pos;
	int				target;
	int				act_a;
	int				act_b;
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
int		lst_size(t_stack *stack);
t_stack	*lstnew(int num);

/*
Function will sort the list
*/
void	sort_small(t_stack **stack_a, int len);
void	sort_big(t_stack **stack_a, t_stack **stack_b, int len);
void	sort_stack(t_stack **s_a, t_stack **s_b, int act_a, int act_b);

/*
Functions/actions for swap the nodes in stack.
*/
void	do_ra(t_stack **stack);
void	do_rb(t_stack **stack);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack);
void	do_rrb(t_stack **stack);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_b, t_stack **stack_a);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

/*
Function utils
*/
int		check_sorted(t_stack *stack);
void	set_data(t_stack **stack_a, t_stack **stack_b, int len);

#endif
