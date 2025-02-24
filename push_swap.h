#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"
#include <stdio.h> // bu silinicek

typedef struct s_list
{
	int	content;
	struct s_list	*next;
}	Stack;
typedef struct s_lists
{
	Stack	*a;
	Stack	*b;
} Stacks;

void	error(char *message, Stack **stack, char **argv);
Stack	*new_stack(int num);
Stack	*get_last(Stack *stack);
void	stack_push(Stack **head, Stack *stack);
void 	free_stack(Stack *stack);








#endif