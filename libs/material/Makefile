NAME = material.a

SRC = material.c \

OBJ = $(SRC:.c=.o)

PATTERN_DIR = ../pattern


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(PATTERN_DIR)/pattern.a
	ar rcs $(NAME) $(OBJ)

$(PATTERN_DIR)/pattern.a:
	$(MAKE) -C $(PATTERN_DIR)

all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PATTERN_DIR) fclean

.PHONY: clean re fclean all