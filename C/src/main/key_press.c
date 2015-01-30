#include "wolf3d.h"

void	h_mov_press(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = add_option(*mov, FORWARD);
	if (key == XK_Down || key == XK_s)
		*mov = add_option(*mov, BACKWARD);
	if (key == XK_a)
		*mov = add_option(*mov, LEFT);
	if (key == XK_d)
		*mov = add_option(*mov, RIGHT);
}

void	v_mov_press(int key, int *mov)
{
	if (key == XK_t)
		*mov = add_option(*mov, UP);
	if (key == XK_g)
		*mov = add_option(*mov, DOWN);
}

void	h_rot_press(int key, int *rot)
{
	if (key == XK_r)
		*rot = add_option(*rot, ROT_UP);
	if (key == XK_f)
		*rot = add_option(*rot, ROT_DOWN);
}

void	v_rot_press(int key, int *rot)
{
	if (key == XK_Left || key == XK_q)
		*rot = add_option(*rot, ROT_LEFT);
	if (key == XK_Right || key == XK_e)
		*rot = add_option(*rot, ROT_RIGHT);
}
