# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 14:24:57 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/31 14:02:40 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c\
	   utils_so_long_map.c\
	   utils_so_long_keyhooks.c\
	   get_next_line.c\
	   get_next_line_utils.c\

OBJ = $(SRCS:.c=.o)

RM = rm -f
ARC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g
CC = cc


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit 

re: clean all

t: re
	./$(NAME) ./map.ber

lldb: re
	lldb $(NAME) ./map.ber
val: re
	valgrind --leak-check=full --suppressions=suppression_valgrind ./$(NAME)

.PHONY:
	all clean re fclean val lldb t
