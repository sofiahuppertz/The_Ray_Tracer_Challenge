NAME = comps.a

SRC = comps.c \
	comps_helpers.c \

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
	$(MAKE) -C $(SHAPE_DIR) fclean

.PHONY: clean re fclean all