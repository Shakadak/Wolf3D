PSX	:=	collision.c

OBJ := $(OBJ) $(PSX:.c=.o)

$(DIROBJ)/%.o: $(DIRPSX)/%.c $(HEAD)
	$(COMPIL)
