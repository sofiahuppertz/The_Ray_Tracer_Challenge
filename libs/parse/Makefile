NAME = parse.a

SRC = parse.c \
		read_line.c \
		utils.c \
		utils_2.c \
		scene_elm.c \
		scene_elm_2.c \
		syntax_check.c \
		syntax_check_utils.c \
		check_extra.c \
		extra.c \
		extra_utils.c \
		make_utils.c \

SCENE_DIR = ../scene
LIBFT_DIR = ../libft

OBJ = $(SRC:.c=.o)

.SECONDARY: $(OBJ)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ) $(LIBFT_DIR) $(SCENE_DIR)/scene.a $(LIBFT_DIR)/libft.a
	ar rcs $(NAME) $(OBJ)
	

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(SCENE_DIR)/scene.a:
	$(MAKE) -C $(SCENE_DIR)

clean :
	rm -f $(OBJ)
	make -C $(SCENE_DIR) fclean
	make -C $(LIBFT_DIR) fclean

fclean : clean
	rm -f $(NAME)
	

re : fclean all

.PHONY: all bonus clean fclean re