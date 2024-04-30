NAME = pattern.a

SRC = pattern.c \
	pattern_methods.c \
	stripe.c \
	gradient.c \
	ring.c \
	checker.c \
	solid.c \
	blended.c \
	test_pattern.c \

OBJ = $(SRC:.c=.o)

TUPLE_DIR = ../tuple

COLOR_DIR = ../color

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(TUPLE_DIR)/tuple.a $(COLOR_DIR)/color.a
	ar rcs $(NAME) $(OBJ)


$(TUPLE_DIR)/tuple.a:
	$(MAKE) -C $(TUPLE_DIR)

$(COLOR_DIR)/color.a:
	$(MAKE) -C $(COLOR_DIR)
	
all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(TUPLE_DIR) fclean
	$(MAKE) -C $(COLOR_DIR) fclean

.PHONY: clean re fclean all