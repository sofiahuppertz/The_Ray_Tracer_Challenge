NAME = light.a

SRC = light.c \
	phong_reflection_model.c \

OBJ = $(SRC:.c=.o)

COMPS_DIR = ../comps


.SECONDARY: $(OBJ)

%.o: %.c
	cc -g -Wall -Wextra -Werror  -I. -c $< -o $@

$(NAME): $(OBJ) $(COMPS_DIR)/comps.a
	ar rcs $(NAME) $(OBJ)


$(COMPS_DIR)/comps.a:
	$(MAKE) -C $(COMPS_DIR)

	
all: $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(COMPS_DIR) fclean

.PHONY: clean re fclean all