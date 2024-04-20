NAME = matrix.a

SRC = matrix.c \
	matrix_operations.c \
	matrix_transformations.c 

OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean re fclean all