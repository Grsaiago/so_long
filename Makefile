# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 14:24:57 by gsaiago           #+#    #+#              #
#    Updated: 2022/09/09 15:36:24 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c\
	   utils_so_long_exit.c\
	   utils_so_long_map.c\
	   utils_so_long_map1.c\
	   utils_so_long_keyhooks.c\
	   get_next_line.c\
	   get_next_line_utils.c\

MAP = ./map.ber
RM = rm -f
CC = cc -Wall -Wextra -Werror
DO_MLX = ./mlx/libmlx.a

all: $(NAME)

clean: 
	@make clean -C ./mlx 

fclean: clean 
	@rm -f $(NAME)

$(NAME): $(DO_MLX) $(SRCS)
		@$(CC) -o $(NAME) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit 
		@echo "So_long done ✅"

$(DO_MLX):
	@make -C ./mlx

re: clean all

t: re
	@./$(NAME) $(MAP)

lldb: re
	@lldb $(NAME) $(MAP)
val: re
	@valgrind --leak-check=full --suppressions=suppression_valgrind ./$(NAME) $(MAP)

.PHONY:
	all clean re fclean val lldb t
