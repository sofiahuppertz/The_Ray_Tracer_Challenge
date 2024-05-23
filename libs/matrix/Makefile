NAME = matrix.a

SRC = matrix.c \
	matrix_operations.c \
	matrix_operations_2.c \
	matrix_operations_3.c \
	matrix_transformations.c \
	matrix_transformations_2.c \

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