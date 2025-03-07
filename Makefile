# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 21:21:11 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/07 13:58:04 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = cc -Wall -Wextra -Werror

SOURCES = push_swap.c push_swap_utils.c stack_functions.c stack_utils.c binary_radix_sort.c \
		  sort_small.c is_sorted.c

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