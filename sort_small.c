/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:56:16 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/07 13:49:37 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_stack(a, "sa\n");
	if ((*a)->next->content > (*a)->next->next->content)
		reverse_rotate(a, "rra\n");
	if ((*a)->next->content < (*a)->content)
		swap_stack(a, "sa\n");
}

static void	put_int_top(t_stack **a, int idx)
{
	while ((*a) != NULL && (*a)->index != idx)
		rotate_stack(a, "ra\n");
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_stack(a, "sa\n");
	else if (size == 3)
		sort_three(a);
	if (get_last(*a)->index == 0)
		reverse_rotate(a, "rra\n");
	if (size == 4)
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
