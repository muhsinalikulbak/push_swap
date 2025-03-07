/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:56:16 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/07 08:05:56 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	int first = (*a)->index;
	int second = (*a)->next->index;
	int third = (*a)->next->next->index;

	if (first < second && second > third && first < third)
		// 1,3,2 durumu
		swap_stack(a, "sa\n");
	else if (first > second && second > third)
		// 3,2,1 durumu
		{
			swap_stack(a, "sa\n");
			reverse_rotate(a, "rra\n");
		}
	else if (first > second && second < third && first > third)
		// 3,1,2 durumu
		rotate_stack(a, "ra\n");
	else if (first > second && second < third && first < third)
		// 2,1,3 durumu
		swap_stack(a, "sa\n");
	else if (first < second && second > third && first > third)
		// 2,3,1 durumu
		reverse_rotate(a, "rra\n");
	// 1,2,3 durumu için işlem gerekmez
}
static void	put_int_top(t_stack **a, int idx)
{
	while ((*a) != NULL && (*a)->index != idx)
		rotate_stack(a, "ra\n");
}

void sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
	{
		put_int_top(a, 0);
		push_stack(a, b, "pb\n");
		sort_three(a);
		push_stack(b, a, "pa\n");
	}
	else if (size == 5)
	{
		put_int_top(a, 0);
		push_stack(a, b, "pb\n");
		put_int_top(a, 1);
		push_stack(a, b, "pb\n");
		sort_three(a);
		push_stack(b, a, "pa\n");
		push_stack(b, a, "pa\n");
	}
}

