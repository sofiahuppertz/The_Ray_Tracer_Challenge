NAME = cylinder.a

SRC = cylinder.c \
	cylinder_methods.c \

OBJ = $(SRC:.c=.o)

CYLINDRICAL_DIR = ../cylindrical


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(CYLINDRICAL_DIR)/cylindrical.a
	ar rcs $(NAME) $(OBJ)

$(CYLINDRICAL_DIR)/cylindrical.a:
	$(MAKE) -C $(CYLINDRICAL_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(CYLINDRICAL_DIR) clean

.PHONY: clean re fclean all