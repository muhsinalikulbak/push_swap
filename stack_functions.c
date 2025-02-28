/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:57:11 by mkulbak           #+#    #+#             */
/*   Updated: 2025/02/28 15:47:09 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack, char *stack_type)
{
	t_stack *temp1;
	t_stack *temp2;
	t_stack *temp3;

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
	write(1, stack_type, 3);
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap_stack(a, "sa\n");
	swap_stack(b, "sb\n");
}

void	push_stack(t_stack **stack1, t_stack **stack2, char *push_name)
{
	if (!*stack1)
		return ;
	add_last(stack2, get_last(*stack1));
	delete_last(stack1);
	write(1, push_name, 3);
}
