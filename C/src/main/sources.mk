MAIN	:=	main.c \
		direction.c \
		movement.c \
		options.c \
		is_key.c \
		horizontal_rotation.c \
		vertical_rotation.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
