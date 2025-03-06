/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:33:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/06 14:50:34 by mkulbak          ###   ########.fr       */
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

int	max_num(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else if (num2 > num1)
		return (num2);
	return (0);
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
		max = max_num(max, temp->index);
		temp = temp->next;
	}
	while (max > 0)
	{
		bit_count++;
		max = max >> 1;
	}
	return (bit_count);
}

void	radix(t_stack **a, t_stack **b)
{
	int	i;
	int	size;
	int	j;
	int	msb;

	msb = get_msb(a);
	i = 0;
	size = stack_size(*a);
	while (i < msb)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_stack(a, b, "pb\n");
			else
				rotate_stack(a, "ra\n");
			j++;
		}
		while (*b)
			push_stack(b, a, "pa\n");
		i++;
	}
}
