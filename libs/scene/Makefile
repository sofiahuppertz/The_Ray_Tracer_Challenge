NAME = scene.a

SRC = attributes.c \
	attributes_2.c \
	scene.c \
	make_cone.c \
	make_cylinder.c \
	make_plane.c \
	make_sphere.c \
	methods1.c \
	window.c \

CAMERA_DIR = ../camera

OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(CAMERA_DIR)/camera.a
	ar rcs $(NAME) $(OBJ)

$(CAMERA_DIR)/camera.a:
	$(MAKE) -C $(CAMERA_DIR)

all: $(NAME)

re : fclean all


fclean: clean
	rm -f $(NAME)
	make -C $(CAMERA_DIR) fclean

clean:
	rm -f $(OBJ)

.PHONY: clean re fclean all