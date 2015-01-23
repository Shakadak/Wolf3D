INI	:=	hook_initialization.c \
		map_init.c \
		player_init.c

OBJ := $(OBJ) $(INI:.c=.o)

$(DIROBJ)/%.o: $(DIRINI)/%.c $(HEAD)
	$(COMPIL)
