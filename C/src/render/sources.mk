RDR	:=	render.c

OBJ := $(OBJ) $(RDR:.c=.o)

$(DIROBJ)/%.o: $(DIRRDR)/%.c $(HEAD)
	$(COMPIL)
