#include "wolf3d.h"

void		rotation_press(int key, int *rot)
{
	if (key == XK_Left || key == XK_a)
		*rot = add_option(*rot, COUNTER);
	if (key == XK_Right || key == XK_d)
		*rot = add_option(*rot, CLOCK);
}

void		rotation_release(int key, int *rot)
{
	if (key == XK_Left || key == XK_a)
		*rot = rem_option(*rot, COUNTER);
	if (key == XK_Right || key == XK_d)
		*rot = rem_option(*rot, CLOCK);
}

static int	rot_left(t_player *c)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(-ROT) - c->dir.y * sin(-ROT);
	c->dir.y = odirx * sin(-ROT) + c->dir.y * cos(-ROT);
	c->cam.x = c->cam.x * cos(-ROT) - c->cam.y * sin(-ROT);
	c->cam.y = ocamx * sin(-ROT) + c->cam.y * cos(-ROT);
	return (2);
}

static int	rot_right(t_player *c)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(ROT) - c->dir.y * sin(ROT);
	c->dir.y = odirx * sin(ROT) + c->dir.y * cos(ROT);
	c->cam.x = c->cam.x * cos(ROT) - c->cam.y * sin(ROT);
	c->cam.y = ocamx * sin(ROT) + c->cam.y * cos(ROT);
	return (2);
}

int			rotate(t_env *env)
{
	if ((env->player.rot & (CLOCK | COUNTER)) == CLOCK)
		rot_right(&env->player);
	if ((env->player.rot & (CLOCK | COUNTER)) == COUNTER)
		rot_left(&env->player);
	return (0);
}
