/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:57:11 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/06 14:42:28 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack, char *stack_name)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (stack_size(*stack) < 2)
		return ;
	if (stack_size(*stack) == 2)
	{
		temp1 = (*stack)->next;
		temp1->next = *stack;
		temp1->next->next = NULL;
		*stack = temp1;
		return ;
	}
	temp1 = *stack;
	while (temp1->next->next->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp3 = temp2->next;
	temp1->next = temp3;
	temp3->next = temp2;
	temp2->next = NULL;
	write(1, stack_name, 3);
}

void	push_stack(t_stack **stack1, t_stack **stack2, char *push_name)
{
	t_stack	*temp;

	if (!*stack1)
		return ;
	temp = *stack1;
	*stack1 = (*stack1)->next;
	temp->next = *stack2;
	*stack2 = temp;
	write(1, push_name, 3);
}

void	rotate_stack(t_stack **stack, char *rotate_name)
{
	t_stack	*temp;

	if (*stack == NULL || stack_size(*stack) == 1)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	add_last(stack, temp);
	write(1, rotate_name, 3);
}

void	reverse_rotate(t_stack **stack, char *rev_rotate_name)
{
	t_stack	*temp;

	if (!*stack || stack_size(*stack) == 1)
		return ;
	temp = get_last(*stack);
	delete_last(stack);
	temp->next = *stack;
	*stack = temp;
	write(1, rev_rotate_name, 4);
}
