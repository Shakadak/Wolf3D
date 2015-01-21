INI	:=	window_initialization.c

OBJ := $(OBJ) $(INI:.c=.o)

$(DIROBJ)/%.o: $(DIRINI)/%.c $(HEAD)
	$(COMPIL)
