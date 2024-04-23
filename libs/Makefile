NAME = librt.a

SUBDIRS = camera \
		canvas \
		color \
		intersection \
		light \
		matrix \
		pattern \
		plane \
		ray \
		shape \
		sphere \
		tuple \
		world \

LIBS = $(addsuffix /$@, $(SUBDIRS))

all: $(NAME)

$(NAME): $(SUBDIRS)
	ar rcs $@ $(foreach dir, $(SUBDIRS), $(dir)/*.o)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(SUBDIRS) clean fclean re