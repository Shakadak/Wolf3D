NAME	:=	wolf3d

### DIRECTORIES ###

DIRSRC	:=	src
DIROBJ	:=	obj
DIRINC	:=	inc
DIRLIB	:=	libft

### FILES ###

HEAD := $(DIRINC)/$(NAME).h

OBJ	:=

include $(DIRSRC)/sources.mk

POBJ	:=	$(addprefix $(DIROBJ)/, $(OBJ))

### COMPILATION VARIABLES ###

C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3

C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)ludes \
			-I /usr/x11/include

L_FLAG	:=	-L $(DIRLIB) -lft \
			-L /usr/X11/lib -lmlx -lXext -lX11

COMPIL	= $(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	= $(CC) -o $@ $^ $(L_FLAG)


### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(NAME)

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	$(LINK)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### MISC ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
