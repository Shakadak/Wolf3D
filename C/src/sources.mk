SRC	:=	main.c \
		check.c \
		ray.c \
		hook_initialization.c \
		window_initialization.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	$(COMPIL)
