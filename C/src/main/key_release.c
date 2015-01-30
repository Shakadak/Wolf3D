#include "wolf3d.h"

void	h_mov_release(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = rem_option(*mov, FORWARD);
	if (key == XK_Down || key == XK_s)
		*mov = rem_option(*mov, BACKWARD);
	if (key == XK_a)
		*mov = rem_option(*mov, LEFT);
	if (key == XK_d)
		*mov = rem_option(*mov, RIGHT);
}

void	v_mov_release(int key, int *mov)
{
	if (key == XK_t)
		*mov = rem_option(*mov, UP);
	if (key == XK_g)
		*mov = rem_option(*mov, DOWN);
}

void	h_rot_release(int key, int *rot)
{
	if (key == XK_r)
		*rot = rem_option(*rot, ROT_UP);
	if (key == XK_f)
		*rot = rem_option(*rot, ROT_DOWN);
}

void	v_rot_release(int key, int *rot)
{
	if (key == XK_Left || key == XK_q)
		*rot = rem_option(*rot, ROT_LEFT);
	if (key == XK_Right || key == XK_e)
		*rot = rem_option(*rot, ROT_RIGHT);
}
