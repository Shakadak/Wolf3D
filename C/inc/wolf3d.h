#ifndef WOLF3D_H
# define WOLF3D_H

#include <X11/keysym.h>
#include <mlx.h>
#include "libft.h"

# define W_WIDTH 1900
# define W_HEIGHT 1200
# define W_TITLE "Wolf3D"

void	*init();
void	*new_window(void *env);
int		key_hook(int key_code);
#endif
