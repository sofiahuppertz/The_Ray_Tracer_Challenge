NAME = intersection.a

SRC = camera.c \

OBJ = $(SRC:.c=.o)

RAY_DIR = ../ray
MATRIX_DIR = ../matrix
MLX_HELPERS_DIR = ../mlx_helpers
WORLD_DIR = ../world

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(RAY_DIR)/ray.a $(MATRIX_DIR)/matrix.a $(MLX_HELPERS_DIR)/mlx_helpers.a $(WORLD_DIR)/world.a
	ar rcs $(NAME) $(OBJ)


$(RAY_DIR)/ray.a:
	$(MAKE) -C $(RAY_DIR)

$(MATRIX_DIR)/matrix.a:
	$(MAKE) -C $(MATRIX_DIR)

$(MLX_HELPERS_DIR)/mlx_helpers.a:
	$(MAKE) -C $(MLX_HELPERS_DIR)

$(WORLD_DIR)/world.a:
	$(MAKE) -C $(WORLD_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(RAY_DIR) fclean

.PHONY: clean re fclean all