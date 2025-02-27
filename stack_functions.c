/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:57:11 by mkulbak           #+#    #+#             */
/*   Updated: 2025/02/28 01:41:20 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack *temp1;
	t_stack *temp2;
	t_stack *temp3;

	if (stack_size(*a) < 2)
		return ;
	if (stack_size(*a) == 2)
	{
		temp1 = (*a)->next;
		temp1->next = *a;
		temp1->next->next = NULL;
		*a = temp1;
		return ;
	}
	temp1 = *a;
	while (temp1->next->next->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp3 = temp2->next;
	temp1->next = temp3;
	temp3->next = temp2;
	temp2->next = NULL;
}
