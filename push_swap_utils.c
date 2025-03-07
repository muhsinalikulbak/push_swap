/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/07 05:59:46 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_last(t_stack **stack)
{
	t_stack	*temp;

	if (stack_size(*stack) == 0)
		return ;
	if (stack_size(*stack) == 1)
		*stack = NULL;
	else
	{
		temp = *stack;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next = NULL;
	}
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap_stack(a, "sa\n");
	swap_stack(b, "sb\n");
}

void	rotate_all(t_stack **a, t_stack **b)
{
	rotate_stack(a, "ra\n");
	rotate_stack(b, "rb\n");
}

void	reverse_rotate_all(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "rra\n");
	reverse_rotate(b, "rrb\n");
}

void	error(char *message, t_stack **stack, char **argv)
{
	if (argv != NULL)
		free_all(argv);
	if (stack != NULL && *stack != NULL)
		free_stack(*stack);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int	i;

	i = 0;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->index != i)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}