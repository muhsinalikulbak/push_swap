# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 21:21:11 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/07 07:32:38 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = gcc -Wall -Wextra -Werror

SOURCES = push_swap.c push_swap_utils.c stack_functions.c stack_utils.c binary_radix_sort.c \
		  sort_small.c

LIBFT = libft/libft.a



all: $(NAME)


$(NAME): $(SOURCES)
	make -C ./libft -s 
	$(CFLAGS)  -o $(NAME) $(SOURCES) $(LIBFT)

clean:
	make clean -C ./libft -s

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re