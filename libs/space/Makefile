NAME = space.a

SRC = draw_sphere.c \

OBJ = $(SRC:.c=.o)

INTERSECTION_DIR = ../intersection
MLX_HELP_DIR = ../mlx_helpers
LIGHT_DIR = ../light


.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ) $(INTERSECTION_DIR)/intersection.a $(MLX_HELP_DIR)/mlx_helpers.a $(LIGHT_DIR)/light.a 
	ar rcs $(NAME) $(OBJ)

$(INTERSECTION_DIR)/intersection.a:
	$(MAKE) -C $(INTERSECTION_DIR)

$(MLX_HELP_DIR)/mlx_helpers.a:
	$(MAKE) -C $(MLX_HELP_DIR)

$(LIGHT_DIR)/light.a:
	$(MAKE) -C $(LIGHT_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(COLOR_DIR) fclean

.PHONY: clean re fclean all