# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2015/01/21 17:36:19 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftmlx.a

### DIRECTORIES ###

DIRSRC		:=	src
DIROBJ		:=	obj
DIRINI		:=	$(DIRSRC)/ini
DIRMSC		:=	$(DIRSRC)/msc
DIRPIX		:=	$(DIRSRC)/pix
DIRINC		:=	inc

### FILES ###

### FILES: SOURCES ###

include $(DIRINI)/sources.mk
include $(DIRMSC)/sources.mk
include $(DIRPIX)/sources.mk

### FILES: OBJECTS ###

OBJ			:=	$(PIX:.c=.o)

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
INC			:=	$(DIRINC)/libftmlx.h

### ARCHIVE ###

AR			:=	ar
AR_FLAG		:=	-crus
AR_EXEC		=	$(AR) $(AR_FLAG) $@ $^

### COMPILATION ###

CC			:=	clang
C_FLAG		:=	-Wall -Wextra -Werror
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< -I $(DIRINC)
COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)

### RULES ###

all: $(NAME)

### RULES: ARCHIVE ###

$(NAME): $(POBJ)
	$(AR_EXEC)

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

clean:
	@(rm -f $(POBJ))

fclean: clean
	@(rm -f $(NAME))

re: fclean $(NAME)

.PHONY: all clean re fclean
