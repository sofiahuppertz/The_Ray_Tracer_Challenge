NAME = intersection.a

SRC = intersection.c \

OBJ = $(SRC:.c=.o)

RAY_DIR = ../ray

.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(RAY_DIR)/ray.a
	ar rcs $(NAME) $(OBJ)

$(RAY_DIR)/ray.a:
	$(MAKE) -C $(RAY_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(RAY_DIR) fclean

.PHONY: clean re fclean all