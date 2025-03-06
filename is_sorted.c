/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:48:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/06 23:53:15 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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