NAME = sphere.a

SRC = sphere.c \

OBJ = $(SRC:.c=.o)

MATRIX_DIR = ../MATRIX

.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

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