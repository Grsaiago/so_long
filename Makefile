# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 14:24:57 by gsaiago           #+#    #+#              #
#    Updated: 2022/09/20 18:42:26 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

COMMON =	./common/utils_so_long_exit.c\
			./common/utils_so_long_exit1.c\
	   		./common/utils_so_long_map.c\
	   		./common/utils_so_long_map1.c\
	   		./common/get_next_line.c\
	   		./common/get_next_line_utils.c\

MANDATORY =	./mandatory/so_long.c\
	   		./mandatory/utils_so_long_keyhooks.c\
			
BONUS_F	=	./bonus/so_long_bonus.c\
			./bonus/utils_so_long_bonus.c\
			./bonus/utils_so_long_keyhooks_bonus.c\

MAP = ./map.ber
RM = rm -f
CC = cc -g -Wall -Wextra -Werror
DO_MLX = ./mlx/libmlx.a

all: $(NAME)

clean: 
	@make clean -C ./mlx
	@rm -rf $(NAME).dSYM	
	@rm -rf $(BONUS_NAME).dSYM	

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf *.dSYM

$(NAME): $(DO_MLX) $(COMMON) $(MANDATORY) 
		@$(CC) -o $(NAME) $(COMMON) $(MANDATORY) -Lmlx -lmlx -framework OpenGL -framework AppKit 
		@echo "So_long done ✅"

$(DO_MLX):
	@make -C ./mlx

re: clean all

t: re
	@./$(NAME) $(MAP)

lldb: re
	@lldb $(NAME) $(MAP)
val: re
	@valgrind --suppressions=val.supp ./$(NAME) $(MAP)

bonus: $(DO_MLX) $(COMMON) $(BONUS_F)
		@$(CC) -o $(BONUS_NAME) $(COMMON) $(BONUS_F) -Lmlx -lmlx -framework OpenGL -framework AppKit
		@echo "So_long_bonus done ✅"

.PHONY:
	all clean re fclean bonus val lldb t
