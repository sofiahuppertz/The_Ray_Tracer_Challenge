NAME = shape.a

SRC = shape.c \
	shape_methods.c \

OBJ = $(SRC:.c=.o)


PATTERN_DIR = ../pattern
MATRIX_DIR = ../matrix


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(PATTERN_DIR)/pattern.a $(MATRIX_DIR)/matrix.a
	ar rcs $(NAME) $(OBJ)


$(PATTERN_DIR)/pattern.a:
	$(MAKE) -C $(PATTERN_DIR)

$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR)


all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MATRIX_DIR) fclean
	$(MAKE) -C $(PATTERN_DIR) fclean

.PHONY: clean re fclean all