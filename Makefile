# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 20:34:23 by eliashobeik       #+#    #+#              #
#    Updated: 2025/12/29 23:20:19 by eliashobeik      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f

SRC = ft_libft_utils.c ft_misc_utils.c ft_processing_utils.c ft_printf.c ft_processing_utils2.c ft_libft_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
