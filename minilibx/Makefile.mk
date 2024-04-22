##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:41:20 2007 Olivier Crouzet
##

## Please use configure script


INC	=%%%%

UNAME = $(shell uname)
cc	= gcc -g
ifeq ($(UNAME),FreeBSD)
	cc = clang
endif

NAME		= libmlx.a
NAME_UNAME	= libmlx_$(UNAME).a

SRC	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
	mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
	mlx_destroy_display.c

OBJ_DIR 			= obj
OBJ					= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
CFLAGS				= -O3 -I$(INC) -w

MAKEFLAGS 			+= --no-print-directory
TOTAL_FILES     	= $(words $(SRC))
CURRENT_INDEX   	= 0

all	: $(NAME)

$(OBJ_DIR)/%.o: 	%.c
					@mkdir -p $(OBJ_DIR)
					@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
					@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
					@printf "\r$(YELLOW)🔧 $(GREEN)%3d%% $(YELLOW)$(BOLD)Compiling: $(RESET)$(BLUE)$(ITALIC)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
					@$(cc) $(CFLAGS) $(IFLAGS) -c $< -o $@  > /dev/null 2>&1

$(NAME)	: 			$(OBJ)
					@ar -r $(NAME) $(OBJ) > /dev/null 2>&1
					@ranlib $(NAME)  
					@cp $(NAME) $(NAME_UNAME)
					@echo "\n$(BOLD)┗▷$(GREEN)『libmlx.a Created』[✅]$(RESET)"

check: 				all
					@test/run_tests.sh

show:
					@printf "NAME  		: $(NAME)\n"
					@printf "NAME_UNAME	: $(NAME_UNAME)\n"
					@printf "cc		: $(cc)\n"
					@printf "CFLAGS		: $(CFLAGS)\n"
					@printf "SRC		:\n	$(SRC)\n"
					@printf "OBJ		:\n	$(OBJ)\n"

clean	:
					@echo "$(BOLD) [🗑️ ] $(YELLOW)$(REVERSED)Cleaning up the minilibx$(RESET)"
					@rm -rf $(OBJ_DIR)/ $(NAME) $(NAME_UNAME) *~ core *.core  > /dev/null 2>&1
					@echo "┗▷$(YELLOW)『Object files from $(ITALIC)minilibx$(RESET)$(YELLOW) cleaned』$(RESET)"

.PHONY: all check show clean

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m
UNDERLINE := \033[4m
REVERSED := \033[7m
ITALIC := \033[3m