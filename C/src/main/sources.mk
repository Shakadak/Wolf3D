MAIN	:=	main.c \
		movement.c

OBJ := $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
