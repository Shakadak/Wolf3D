PIX	:=	put_pixel_to_image.c \
		clear_image.c

OBJ := $(OBJ) $(PIX:.c=.o)

$(DIROBJ)/%.o: $(DIRPIX)/%.c $(INC)
	$(COMPIL)
