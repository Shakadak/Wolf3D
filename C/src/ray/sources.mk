RAY	:=	dda.c \
		check.c \
		distance.c \
		new_ray.c

OBJ := $(OBJ) $(RAY:.c=.o)

$(DIROBJ)/%.o: $(DIRRAY)/%.c $(HEAD)
	$(COMPIL)
