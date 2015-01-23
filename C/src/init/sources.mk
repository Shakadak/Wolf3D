SRC	:=	hook_initialization.c \
		map_init.c \
		player_init.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(HEAD)
	$(COMPIL)
