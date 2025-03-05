/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:33:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/06 00:46:27 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	int		i;
	int		size;
	int		min;
	t_stack	*temp;
	t_stack	*min_temp;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		temp = *a;
		min = INT_MAX;
		while (temp != NULL)
		{
			if (temp->index == DEFAULT && temp->content <= min)
			{
				min = temp->content;
				min_temp = temp;
			}
			temp = temp->next;
		}
		min_temp->index = i;
		i++;
	}
}

static int	get_msb(t_stack **a)
{
	int		max;
	int		bit_count;
	t_stack	*temp;

	max = 0;
	temp = *a;
	bit_count = 0;
	while (temp != NULL)
	{
		max = MAX(max, temp->index);
		temp = temp->next;
	}
	while (max > 0)
	{
		bit_count++;
		max = max >> 1;
	}
	return (bit_count);
}
static void	push_a(t_stack **a, t_stack **b)
{
	while (*b != NULL)
		push_stack(b, a, "pa\n");
}

void	radix(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	int		msb_size;
	t_stack *temp;

	msb_size = get_msb(a);
	i = -1;
	while (++i < msb_size)
	{
		temp = *a;
		j = -1;
		while (++j < stack_size(*a))
		{
			if (temp != NULL && ((temp->index >> i ) & 1) == 0)
				push_stack(a, b, "pb\n");
			else if (temp != NULL)
				rotate_stack(a, "ra\n");
			temp = *a;
		}
		push_a(a, b);
	}
}
