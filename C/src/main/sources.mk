MAIN	:=	main.c \
		direction.c \
		movement.c \
		options.c \
		rotation.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
