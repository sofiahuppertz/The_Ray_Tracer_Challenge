NAME = shape.a

SRC = shape.c \
	shape_methods.c \

OBJ = $(SRC:.c=.o)


LIGHT_DIR = ../light
MATRIX_DIR = ../matrix


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(LIGHT_DIR)/light.a $(MATRIX_DIR)/matrix.a
	ar rcs $(NAME) $(OBJ)


$(LIGHT_DIR)/light.a:
	$(MAKE) -C $(LIGHT_DIR)

$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR)


all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MATRIX_DIR) fclean
	$(MAKE) -C $(LIGHT_DIR) fclean

.PHONY: clean re fclean all