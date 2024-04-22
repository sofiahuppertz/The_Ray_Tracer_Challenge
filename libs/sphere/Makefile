NAME = sphere.a

SRC = sphere.c \
	sphere_methods.c \

OBJ = $(SRC:.c=.o)

TUPLE_DIR = ../tuple
SHAPE_DIR = ../shape


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(TUPLE_DIR)/tuple.a $(SHAPE_DIR)/shape.a
	ar rcs $(NAME) $(OBJ)

$(TUPLE_DIR)/tuple.a:
	$(MAKE) -C $(TUPLE_DIR)

$(SHAPE_DIR)/shape.a:
	$(MAKE) -C $(SHAPE_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(TUPLE_DIR) clean
	$(MAKE) -C $(SHAPE_DIR) clean

.PHONY: clean re fclean all