# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 14:57:04 by tlouekar          #+#    #+#              #
#    Updated: 2020/01/09 10:04:01 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit_srcs/main.c \
		fillit_srcs/validate.c \
		fillit_srcs/solve.c \
		fillit_srcs/scan_save_tetramino.c \
		fillit_srcs/print_grid.c \

OBJS = 	validate.o \
		solve.o \
		scan_save_tetramino.o \
		print_grid.o \
		main.o \

INCL = -I ./fillit_srcs -I ./libft/includes/

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(CFLAGS) -c $(SRCS) $(INCS)
	@gcc $(CFLAGS) $(INCS) $(OBJS) $(LIB) -o $(NAME)
	@mkdir fillit_objs
	@mv $(OBJS) fillit_objs

.PHONY: clean fclean re all

clean:
	@rm -rf fillit_objs
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
