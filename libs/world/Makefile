NAME = world.a

SRC = world.c \
	world_utils.c \
	world_methods.c \
	shadow.c \
	reflection.c \
	refraction.c \
	reflectance.c \

OBJ = $(SRC:.c=.o)


LIGHT_DIR = ../light
COMPS_DIR = ../comps

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(LIGHT_DIR)/light.a $(COMPS_DIR)/comps.a
	ar rcs $(NAME) $(OBJ)

$(LIGHT_DIR)/light.a:
	$(MAKE) -C $(LIGHT_DIR)

$(COMPS_DIR)/comps.a:
	$(MAKE) -C $(COMPS_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(COMPS_DIR) fclean
	$(MAKE) -C $(LIGHT_DIR) fclean

.PHONY: clean re fclean all