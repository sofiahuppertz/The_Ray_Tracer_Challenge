NAME = miniRT
SRC = main.c
OBJ = $(SRC:.c=.o)

INCLUDES = -Ilibs -Iminilibx

MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm -lz
MLX_PATH = minilibx

RT_FLAGS = -Llibs -lrt
RT_PATH = libs

# ANSI escape codes for colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

%.o: %.c
	@echo "${YELLOW}Compiling $<...${NC}"
	@cc -g -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

$(NAME): $(MLX_PATH)/libmlx.a $(RT_PATH)/librt.a $(OBJ)
	@echo "${BLUE}Compiling MINIRT...${NC}"
	@cc $(OBJ) $(RT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "${GREEN}DONE${NC}"
	@echo "${GREEN}Have fun :)${NC}"

$(MLX_PATH)/libmlx.a:
	@echo "${YELLOW}Building MiniLibX...${NC}"
	@make -C $(MLX_PATH) > /dev/null 2>&1

$(RT_PATH)/librt.a:
	@echo "${YELLOW}Building RT library...${NC}"
	@make -C $(RT_PATH) > /dev/null 2>&1

all: $(NAME)

clean:
	@echo "${RED}Deleting object files...${NC}"
	@rm -f $(OBJ)
	@echo "${RED}Cleaning MiniLibX...${NC}"
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@echo "${RED}Cleaning RT library...${NC}"
	@make -C $(RT_PATH) fclean > /dev/null 2>&1

fclean: clean
	@echo "${RED}Deleting executable...${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
