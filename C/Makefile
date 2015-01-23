# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 12:57:00 by npineau           #+#    #+#              #
#    Updated: 2015/01/23 17:25:09 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	wolf3d

### DIRECTORIES ###

DIRSRC	:=	src
DIROBJ	:=	obj
DIRINC	:=	inc
DIRFT	:=	libft
DIRMLX	:=	libumlx
DIRMAIN	:=	$(DIRSRC)/main
DIRINI	:=	$(DIRSRC)/init
DIRRAY	:=	$(DIRSRC)/ray
DIRRDR	:=	$(DIRSRC)/render

### FILES ###

HEAD := $(DIRINC)/$(NAME).h

include $(DIRMAIN)/sources.mk
include $(DIRINI)/sources.mk
include $(DIRRAY)/sources.mk
include $(DIRRDR)/sources.mk

POBJ	:=	$(addprefix $(DIROBJ)/, $(OBJ))

PFT		:= $(DIRFT)/libft.a
PMLX	:= $(DIRMLX)/libumlx.a

### COMPILATION VARIABLES ###

C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3

C_INC	:=	-I $(DIRINC) \
			-I $(DIRFT)/$(DIRINC) \
			-I $(DIRMLX)/$(DIRINC) \
			-I /usr/x11/include

L_FLAG	:=	-L $(DIRFT) -lft \
			-L $(DIRMLX) -lumlx \
			-L /usr/X11/lib -lmlx -lXext -lX11

COMPIL	= $(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	= $(CC) -o $@ $^ $(L_FLAG)


### RULES ###

.PHONY: all clean fclean re

all: $(PFT) $(PMLX) $(NAME)

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	$(LINK)

### LIBS ###

$(PFT):
	make -C $(DIRFT)

$(PMLX):
	make -C $(DIRMLX)

### MISC ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

run: $(NAME)
	./$(NAME) map/llapillo.map

re: fclean all
