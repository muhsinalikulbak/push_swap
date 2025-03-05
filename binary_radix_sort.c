/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:33:57 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/05 21:11:34 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	int		i;
	int		size;
	int		prev_min;
	t_stack	*temp;
	t_stack	*min_temp;

	i = 0;
	prev_min = INT_MAX;
	size = stack_size(*a);
	while (i < size)
	{
		temp = *a;
		min_temp = temp;
		while (temp != NULL)
		{
			if (temp->content != prev_min && temp->content < min_temp->content)
				min_temp = temp;
			temp = temp->next;
		}
		min_temp->index = i;
		prev_min = min_temp->content;
		i++;
	}
}
