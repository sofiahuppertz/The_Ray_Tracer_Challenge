#include "mlx_helpers.h"

void	draw_pixel(t_data *data, int x, int y, const t_color *color)
{
	char	*dst;
	unsigned int _color;

	_color = (0xFF << 24) | (color->r << 16) | (color->g << 8) | color->b;
	printf("Color: %d\n", _color);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = _color;
}

t_canvas *canvas(int width, int height)
{
	t_canvas *canvas = (t_canvas *)calloc(1, sizeof(t_canvas));
	if (!canvas)
	{
		printf("Error: memory allocation failed in canvas().\n");
		return NULL;
	}
	canvas->mlx = mlx_init();
	canvas->mlx_win = mlx_new_window(canvas->mlx, width, height, "Default Window Title");
	canvas->img.img = mlx_new_image(canvas->mlx, width, height);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img, &canvas->img.bits_per_pixel, &canvas->img.line_length, &canvas->img.endian);
	return canvas;
}