NAME = cylinder.a

SRC = cylinder.c \
	cylinder_methods.c \

OBJ = $(SRC:.c=.o)

SHAPE_DIR = ../shape


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(SHAPE_DIR)/shape.a
	ar rcs $(NAME) $(OBJ)

$(SHAPE_DIR)/shape.a:
	$(MAKE) -C $(SHAPE_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(SHAPE_DIR) clean

.PHONY: clean re fclean all