SRC	:=	main.c \
		render.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(HEAD)
	$(COMPIL)
