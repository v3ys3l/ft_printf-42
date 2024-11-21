# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 21:37:56 by vbicer            #+#    #+#              #
#    Updated: 2024/11/03 21:37:56 by vbicer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f

SRC	=	ft_printf_utils.c\
ft_printf.c\
ft_putchar.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re