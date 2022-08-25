
NAME = so_long

SRCS = teste.c\
	   utils_minilib.c\
	   get_next_line.c\
	   get_next_line_utils.c\
#	   utils_so_long.c\

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

t: all
	./$(NAME) ./map.ber

.PHONY:
	all clean re fclean
