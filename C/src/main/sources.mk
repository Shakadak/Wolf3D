MAIN	:=	main.c \
		direction.c \
		movement.c \
		options.c \
		is_key.c \
		rotation.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
