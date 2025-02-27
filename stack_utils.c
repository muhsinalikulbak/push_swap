/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:27 by mkulbak           #+#    #+#             */
/*   Updated: 2025/02/28 01:02:50 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*new_stack(int num)
{	
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->content = num;
	stack->next = NULL;
	return (stack);
}

void	stack_push(t_stack **head, t_stack *stack)
{
	t_stack	*last;

	last = get_last(*head);
	if (last == NULL)
		*head = stack;
	else
		last->next = stack;
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (stack)
	{
		while (stack != NULL)
		{
			temp = stack->next;
			free(stack);
			stack = temp;
		}
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
