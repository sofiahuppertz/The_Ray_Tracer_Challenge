NAME = parse

SRC = ./parse.c\
		./read_line.c\
		./utils.c\

OBJ = $(SRC:.c=.o)

INCLUDES = parse.h
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@make -sC libft

clean :
	rm -f $(OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

.PHONY: all bonus clean fclean re