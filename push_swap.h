/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/02/25 19:02:46 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_stack;

void	error(char *message, t_stack **stack, char **argv);
t_stack	*new_stack(int num);
t_stack	*get_last(t_stack *stack);
void	stack_push(t_stack **head, t_stack *stack);
void	free_stack(t_stack *stack);
#endif