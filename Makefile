# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 14:24:57 by gsaiago           #+#    #+#              #
#    Updated: 2022/09/23 12:12:59 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =		so_long.c\
			utils_so_long_exit.c\
			utils_so_long_exit1.c\
	   		utils_so_long_map.c\
			utils_so_long_map1.c\
	   		utils_so_long_map2.c\
			utils_so_long_keyhooks.c\

MAP = ./map.ber
RM = rm -f
CC = cc -g -Wall -Wextra -Werror
DO_MLX = ./mlx/libmlx.a
DO_LIBFT = ./libft/libft.a
LIBFT_LINK = -L./libft -lft

all: $(NAME)


clean: 
	@make clean -C ./mlx
	@make clean -C ./libft
	@rm -rf $(NAME).dSYM	

fclean: clean 
	@rm -f $(NAME)

$(NAME): $(DO_MLX) $(DO_LIBFT)
		@$(CC) -o $(NAME) $(SRCS) $(LIBFT_LINK) -Lmlx -lmlx -framework OpenGL -framework AppKit 
		@echo "So_long done ✅"

$(DO_MLX):
	@make -C ./mlx

$(DO_LIBFT):
	@make -C ./libft

re: clean all

t: re
	@./$(NAME) $(MAP)

lldb: re
	@lldb $(NAME) $(MAP)

val: re
	@valgrind --suppressions=val.supp ./$(NAME) $(MAP)

.PHONY:
	all clean re fclean val lldb t
