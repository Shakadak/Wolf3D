MAIN	:=	main.c \
		direction.c \
		horizontal_movement.c \
		vertical_movement.c \
		options.c \
		key_press.c \
		key_release.c \
		horizontal_rotation.c \
		vertical_rotation.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
