SRC	:=	main.c \
		check.c \
		ft_fatal.c \
		hook_initialization.c \
		map_init.c \
		player_init.c \
		ray.c \
		window_initialization.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	$(COMPIL)
