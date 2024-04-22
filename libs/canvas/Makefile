NAME = canvas.a

SRC = canvas.c \

OBJ = $(SRC:.c=.o)

COLOR_DIR = ../color

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(COLOR_DIR)/color.a
	ar rcs $(NAME) $(OBJ)

$(COLOR_DIR)/color.a:
	$(MAKE) -C $(COLOR_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(COLOR_DIR) fclean

.PHONY: clean re fclean all