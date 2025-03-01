# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 22:23:51 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/01 21:15:15 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		ft_split.c ft_substr.c ft_atol.c ft_strlen.c  ft_isdigit.c ft_strdup.c
		
OBJS			= $(SRCS:.c=.o)
NAME			= libft.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all:			$(NAME) clean

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
