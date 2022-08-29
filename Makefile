
NAME = so_long

SRCS = utils_so_long_map.c\
	   utils_minilib.c\
	   get_next_line.c\
	   get_next_line_utils.c\
#	   utils_so_long_map.c\
#	   so_long.c

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
val: re
	valgrind --leak-check=full --suppressions=suppression_valgrind ./$(NAME)

.PHONY:
	all clean re fclean
