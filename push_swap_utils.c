/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/02/25 19:06:54 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *message, t_stack **stack, char **argv)
{
	if (argv != NULL)
		free_all(argv);
	if (stack != NULL && *stack != NULL)
		free_stack(*stack);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
