RDR	:=	render.c \
		draw_slice.c \
		wall_color.c

OBJ := $(OBJ) $(RDR:.c=.o)

$(DIROBJ)/%.o: $(DIRRDR)/%.c $(HEAD)
	$(COMPIL)
