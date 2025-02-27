# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 18:43:16 by mkulbak           #+#    #+#              #
#    Updated: 2025/02/28 01:37:58 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = ./libft

SRCS = push_swap.c stack_utils.c push_swap_utils.c stack_functions.c

LIBFT_OBJS = ./libft/ft_atol.o ./libft/ft_bzero.o ./libft/ft_isalnum.o ./libft/ft_isalpha.o ./libft/ft_isascii.o ./libft/ft_isdigit.o\
./libft/ft_isprint.o ./libft/ft_memchr.o ./libft/ft_memcmp.o ./libft/ft_striteri.o\
./libft/ft_memcpy.o ./libft/ft_memmove.o ./libft/ft_memset.o ./libft/ft_putendl_fd.o\
./libft/ft_putchar_fd.o ./libft/ft_putstr_fd.o ./libft/ft_putnbr_fd.o\
./libft/ft_strchr.o ./libft/ft_strlcpy.o ./libft/ft_strmapi.o\
./libft/ft_strdup.o ./libft/ft_split.o ./libft/ft_calloc.o ./libft/ft_itoa.o\
./libft/ft_strlen.o ./libft/ft_strncmp.o ./libft/ft_substr.o ./libft/ft_strtrim.o\
./libft/ft_strnstr.o ./libft/ft_strrchr.o ./libft/ft_strjoin.o\
./libft/ft_tolower.o ./libft/ft_toupper.o ./libft/ft_strlcat.o

OBJ = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
		make -C ${LIBFT_DIR}
		ar rcs ${NAME} ${OBJ} ${LIBFT_OBJS}
		$(CC) $(NAME) -o push_swap
		$(RM) $(OBJ)
		
clean:
		make clean -C ${LIBFT_DIR}
		${RM} ${OBJ}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME}
		$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re