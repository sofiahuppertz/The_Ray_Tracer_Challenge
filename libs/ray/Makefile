NAME = ray.a

SRC = ray.c \
		ray_2.c \

OBJ = $(SRC:.c=.o)

MATRIX_DIR = ../matrix
TUPLE_DIR = ../tuple

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(MATRIX_DIR)/matrix.a $(TUPLE_DIR)/tuple.a
	ar rcs $(NAME) $(OBJ)


$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR)

$(TUPLE_DIR)/tuple.a:
	$(MAKE) -C $(TUPLE_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MATRIX_DIR) fclean
	$(MAKE) -C $(TUPLE_DIR) fclean

.PHONY: clean re fclean all