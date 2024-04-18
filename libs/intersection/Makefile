NAME = intersection.a

SRC = intersection.c \
	sphere_intersection.c \

OBJ = $(SRC:.c=.o)

TUPLE_DIR = ../tuple
SPHERE_DIR = ../sphere

.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ) $(TUPLE_DIR)/tuple.a $(SPHERE_DIR)/sphere.a
	ar rcs $(NAME) $(OBJ)

$(TUPLE_DIR)/tuple.a:
	$(MAKE) -C $(TUPLE_DIR)

$(SPHERE_DIR)/sphere.a:
	$(MAKE) -C $(SPHERE_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(TUPLE_DIR) fclean
	$(MAKE) -C $(SPHERE_DIR) fclean

.PHONY: clean re fclean all