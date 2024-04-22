NAME = world.a

SRC = world.c \
	world_methods.c \

OBJ = $(SRC:.c=.o)


LIGHT_DIR = ../light
SHAPE_DIR = ../shape
SPHERE_DIR = ../sphere

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(LIGHT_DIR)/light.a $(SPHERE_DIR)/sphere.a
	ar rcs $(NAME) $(OBJ)

$(LIGHT_DIR)/light.a:
	$(MAKE) -C $(LIGHT_DIR)

$(SPHERE_DIR)/sphere.a:
	$(MAKE) -C $(SPHERE_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(SPHERE_DIR) fclean
	$(MAKE) -C $(LIGHT_DIR) fclean

.PHONY: clean re fclean all