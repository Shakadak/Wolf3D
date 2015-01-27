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

static void	rot_left(t_player *c, double rot)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(-rot) - c->dir.y * sin(-rot);
	c->dir.y = odirx * sin(-rot) + c->dir.y * cos(-rot);
	c->cam.x = c->cam.x * cos(-rot) - c->cam.y * sin(-rot);
	c->cam.y = ocamx * sin(-rot) + c->cam.y * cos(-rot);
}

static void	rot_right(t_player *c, double rot)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(rot) - c->dir.y * sin(rot);
	c->dir.y = odirx * sin(rot) + c->dir.y * cos(rot);
	c->cam.x = c->cam.x * cos(rot) - c->cam.y * sin(rot);
	c->cam.y = ocamx * sin(rot) + c->cam.y * cos(rot);
}

void		rotate(t_env *env, double rot)
{
	if ((env->player.rot & (CLOCK | COUNTER)) == CLOCK)
		rot_right(&env->player, rot);
	if ((env->player.rot & (CLOCK | COUNTER)) == COUNTER)
		rot_left(&env->player, rot);
}
