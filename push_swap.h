/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/08 12:04:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEFAULT -1
# include "libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"
# include <stdio.h>

typedef struct s_list
{
	int				content;
	long			index;
	struct s_list	*next;
}	t_stack;

t_stack	*get_last(t_stack *stack);
t_stack	*new_stack(int num);
int		is_sorted(t_stack **a);
void	set_index(t_stack **a);
int		max_num(int num1, int num2);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	delete_last(t_stack **stack);
void	radix(t_stack **a, t_stack **b);
void	swap_all(t_stack **a, t_stack **b);
void	rotate_all(t_stack **a, t_stack **b);
void	add_last(t_stack **head, t_stack *node);
void	reverse_rotate_all(t_stack **a, t_stack **b);
void	swap_stack(t_stack **stack, char *stack_name);
void	sort_small(t_stack **a, t_stack **b, int size);
void	rotate_stack(t_stack **stack, char *rotate_name);
void	error(char *message, t_stack **stack, char **argv);
void	reverse_rotate(t_stack **stack, char *rev_rotate_name);
void	push_stack(t_stack **stack1, t_stack **stack2, char *push_name);
#endif