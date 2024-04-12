NAME = color.a

SRC = color.c

OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean re fclean all