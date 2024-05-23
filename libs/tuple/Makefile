NAME = tuple.a

SRC = tuple.c \
	tuple_2.c \
	tuple_3.c \
	tuple_4.c \
	tuple_transformations.c \

MATRIX_DIR = ../matrix

OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(MATRIX_DIR)/matrix.a
	ar rcs $(NAME) $(OBJ)

$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MATRIX_DIR) fclean

.PHONY: clean re fclean all