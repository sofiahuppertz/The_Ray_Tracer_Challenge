NAME = intersection.a

SRC = camera.c \

OBJ = $(SRC:.c=.o)

RAY_DIR = ../ray
MATRIX_DIR = ../matrix

.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ) $(RAY_DIR)/ray.a $(MATRIX_DIR)/matrix.a
	ar rcs $(NAME) $(OBJ)


$(RAY_DIR)/ray.a:
	$(MAKE) -C $(RAY_DIR)

$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(RAY_DIR) fclean

.PHONY: clean re fclean all