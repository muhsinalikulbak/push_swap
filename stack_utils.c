#include "push_swap.h"

Stack *get_last(Stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

Stack *new_stack(int num)
{	
	Stack *stack;

	stack = malloc(sizeof(Stack));
	stack->content = num;
	stack->next = NULL;
	return (stack);
}

void stack_push(Stack **head, Stack *stack)
{
	Stack	*last;

	last = get_last(*head);
	if (last == NULL)
		*head = stack;
	else
		last->next = stack;
}

void free_stack(Stack *stack)
{
	Stack	*temp;

	if (stack)
	{
		while (stack != NULL)
		{
			temp = stack->next;
			free(stack);
			stack = temp;
		}
	}
}
