/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:43:11 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/07 13:39:56 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_check(char *str)
{
	int	i;
	int	plus_count;
	int	minus_count;

	plus_count = 0;
	minus_count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			plus_count++;
		else if (str[i] == '-')
			minus_count++;
		else if (!ft_isdigit(str[i]))
			return (1);
	}
	if (plus_count == (int)ft_strlen(str) || minus_count == (int)ft_strlen(str))
		return (1);
	if (plus_count == 0 && minus_count == 0)
		return (0);
	if (plus_count == 1 && minus_count == 0 && str[0] == '+')
		return (0);
	if (plus_count == 0 && minus_count == 1 && str[0] == '-')
		return (0);
	return (1);
}

static void	repeating_num_check(t_stack **stack, long num, int num_len,
	char **str_nums)
{
	t_stack	*temp;

	if (num_len > 11 || num > INT_MAX || num < INT_MIN)
		error("Error\n", stack, str_nums);
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == (int)num)
			error("Error\n", stack, str_nums);
		temp = temp->next;
	}
}

static void	argv_check(t_stack **stack, int argc, char **argv)
{
	char	**str_nums;
	long	num;
	int		i;
	int		j;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		str_nums = ft_split(argv[i], ' ');
		if (str_nums == NULL || str_nums[0] == NULL)
			error("Error\n", stack, str_nums);
		while (str_nums[++j])
		{
			if (digit_check(str_nums[j]) != 0)
				error("Error\n", stack, str_nums);
			num = ft_atol(str_nums[j]);
			repeating_num_check(stack, num, ft_strlen(str_nums[j]), str_nums);
			add_last(stack, new_stack((int)(num)));
		}
		free_all(str_nums);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	argv_check(&a, argc, argv);
	set_index(&a);
	if (is_sorted(&a) == 1)
	{
		if (stack_size(a) < 6)
			sort_small(&a, &b, stack_size(a));
		else
			radix(&a, &b);
	}
	free_stack(a);
	free_stack(b);
}
