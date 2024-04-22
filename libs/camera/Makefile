NAME = intersection.a

SRC = camera.c \

OBJ = $(SRC:.c=.o)


CANVAS_DIR = ../canvas
WORLD_DIR = ../world

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(CANVAS_DIR)/canvas.a $(WORLD_DIR)/world.a
	ar rcs $(NAME) $(OBJ)

$(CANVAS_DIR)/canvas.a:
	$(MAKE) -C $(CANVAS_DIR)

$(WORLD_DIR)/world.a:
	$(MAKE) -C $(WORLD_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(CANVAS_DIR) fclean
	$(MAKE) -C $(WORLD_DIR) fclean

.PHONY: clean re fclean all