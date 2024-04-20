NAME = test
SRC = test.c
OBJ = $(SRC:.c=.o)

INCLUDE = -Iminilibx -Ilibs

MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm -lz
MLX_PATH = minilibx

RT_FLAGS = -Llibs -lrt
RT_PATH = libs


%.o: %.c
	cc -g -Wall -Wextra -Werror  $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(MLX_PATH)/libmlx.a $(RT_PATH)/librt.a
	gcc -o $(NAME) $(OBJ) $(MLX_FLAGS) $(RT_FLAGS)


$(MLX_PATH)/libmlx.a:
	make -C $(MLX_PATH)

$(RT_PATH)/librt.a:
	make -C $(RT_PATH)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean
	make -C $(RT_PATH) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re