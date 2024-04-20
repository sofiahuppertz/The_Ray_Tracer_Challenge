NAME = light.a

SRC = light.c \
	phong_reflection_model.c \

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