#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismus <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 16:34:22 by ismus             #+#    #+#              #
#    Updated: 2017/11/28 16:08:40 by ismus            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	asm

FUNC	=	parcing.c first_test.c error_free.c name_comment.c				\
			check_operation.c change_coord.c create_file.c init.c argum.c	\
			num_oper.c
			

OBJ		=	$(FUNC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

all: $(NAME)

$(NAME): create $(OBJ)
	@$(CC) $(OBJ) -I /new_lib -L ./new_lib -lft -o $(NAME)
	@echo "\x1B[0;32m"$(NAME)" ready!\x1B[0;37m"

create:
	@make -C new_lib/

$(OBJ): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C new_lib/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C new_lib/ fclean
	@rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all $(NAME) re
