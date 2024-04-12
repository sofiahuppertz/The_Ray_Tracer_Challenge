NAME = ray.a

SRC = ray.c

OBJ = $(SRC:.c=.o)

TUPLE_DIR = ../tuple

.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ) $(TUPLE_DIR)/tuple.a
	ar rcs $(NAME) $(OBJ)


$(TUPLE_DIR)/tuple.a:
	$(MAKE) -C $(TUPLE_DIR)
all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean re fclean all