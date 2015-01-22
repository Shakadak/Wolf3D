# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/06 15:13:22 by npineau           #+#    #+#              #
#    Updated: 2014/01/19 18:57:57 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAG = -O3 -Wall -Wextra -Werror

SRCDIR = sources

OBJDIR = objects

INCDIR = includes

LIB = -L SDL2/lib -lSDL2 -lm

SDLH = SDL2/include/SDL2/

SRC = trace.c \
	  raycast.c \
	  main.c \
	  color.c \
	  bump.c \
	  draw.c \
	  init_step_dist.c \
	  init.c \
	  init_player.c \
	  close.c \
	  line_height.c \
	  move.c

SRCPREF = $(addprefix $(SRCDIR)/, $(SRC))

OBJ = $(SRC:.c=.o)

OBJPREF = $(addprefix $(OBJDIR)/, $(OBJ))

$(NAME): $(OBJPREF)
	gcc -o $@ $^ $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/wolf.h
	clang -o $@ -c $< -I $(INCDIR) -I $(SDLH) $(FLAG)

$(OBJDIR):
	@mkdir $(OBJDIR)

SDL2:
	mkdir -p SDL2/junk
	wget http://www.libsdl.org/release/SDL2-2.0.1.tar.gz
	tar xf SDL2-2.0.1.tar.gz
	( cd SDL2-2.0.1 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.1.tar.gz SDL2-2.0.1 SDL2/junk

clean:
	@echo "Removing $(OBJPREF)."
	@rm -f $(OBJPREF)

fclean: clean
	@echo "Removing $(NAME), $(OBJDIR), SDL2."
	@rm -Rf $(NAME) $(OBJDIR) SDL2

re: fclean all

all: SDL2 $(OBJDIR) $(NAME)

.PHONY: clean fclean re all SDL2

# Credits to aviala for the SDL2 rule.
