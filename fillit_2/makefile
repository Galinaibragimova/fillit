# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtonette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:55:01 by mtonette          #+#    #+#              #
#    Updated: 2019/09/16 17:33:00 by mtonette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =  main.c \
	  holes.c \
	  inputfig.c \
	  search.c \
	  service.c \
	  templates.c 

OBJ	= $(SRC:.c=.o)

SRC_PATH	=	src/

SRC_POS	=	$(addprefix $(SRC_PATH),$(SRC))

INC	=	-I includes

LIBFT	= src/libft/libft.a

CC	=	gcc

FLAGS	=	-Wall	-Werror	-Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	make -C ./src/libft/

clean:
	rm -f $(OBJ)
	make clean -C ./src/libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./src/libft/
re: fclean all

.PHONY : all, re, clean, fclean
