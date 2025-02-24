#include "push_swap.h"

void error(char *message, Stack **stack, char **argv)
{
    if (argv != NULL)
        free_all(argv);
    if (stack != NULL && *stack != NULL)
    {
        free_stack(*stack);
        free_stack(*stack);
    }
    write(1, message, ft_strlen(message));
    exit(EXIT_FAILURE);
}
