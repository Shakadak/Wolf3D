#include "libftmlx.h"

void	put_pixel_to_image(t_img *img, t_pixel const pixel)
{
	int	color;
	int	pos;

	// Careful with the endianess
	color = pixel.color.id;
	pos = pixel.coordinate.y * img->lsize
	+ pixel.coordinate.x * (img->bits / 8);
	img->data[pos] = color &255;
	img->data[pos + 1] = color >> 8 &255;
	img->data[pos + 2] = color >> 16 &255;
}
