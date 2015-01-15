SRC	:=	main.c \
		window_initialization.c \
		hook_initialization.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	$(COMPIL)
