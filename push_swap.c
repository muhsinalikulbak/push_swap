#include "push_swap.h"

static int digit_check(char *str)
{
	int i;
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
	if (plus_count == 0 && minus_count == 0)
		return (0);
	if (plus_count == 1 && minus_count == 0 && str[0] == '+')
		return (0);
	if (plus_count == 0 && minus_count == 1 && str[0] == '-')
		return (0);
	return (1);
}

void argv_check(Stack **stack, int argc, char **argv)
{
	char	**str_num;
	long	num;
	int		i;
	int		j;
	
	i = 0;
	while (++i < argc)
	{
		j = -1;
		str_num = ft_split(argv[i], ' ');
		if (str_num == NULL || str_num[0] == NULL)
			error("Error\n", stack, str_num);
		while (str_num[++j])
		{
			if (digit_check(str_num[j]) != 0)
				error("Error\n", stack, str_num);
			num = ft_atol(str_num[j]);
			// Num'ı aldıktan sonra repeat fonksiyonuna gönder önce  ve aşağıdaki kısmı da ekle
			if (num > INT_MAX || num < INT_MIN || ft_strlen(str_num[j]) > 10)
				error("Error\n", stack, str_num);
			stack_push(stack, new_stack((int)(num)));
		}
		free_all(str_num);
	}
}

int main(int argc, char **argv)
{
	Stack *a;
	Stack *temp;
	if (argc < 2)
		error("Error\n", NULL, NULL);
	a = NULL;

	argv_check(&a, argc, argv);
	temp = a;
	while (a != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	free_stack(temp);
}
