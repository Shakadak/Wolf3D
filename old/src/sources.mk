SRC	:=	bump.c \
		close.c \
		color.c \
		draw.c \
		init.c \
		init_player.c \
		init_step_dist.c \
		line_height.c \
		main.c \
		move.c \
		raycast.c \
		trace.c

OBJ := $(OBJ) $(SRC:.c=.o)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(HEAD)
	$(COMPIL)
