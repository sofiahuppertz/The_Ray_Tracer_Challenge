#include "canvas.h"

void	draw_pixel(t_data *data, int x, int y, const t_color *color)
{
	char			*dst;
	unsigned int	_color;
	unsigned int	_r;
	unsigned int	_g;
	unsigned int	_b;

	_r = (unsigned int)(color->r * 255);
	if (_r > 255)
		_r = 255;
	_g = (unsigned int)(color->g * 255);
	if (_g > 255)
		_g = 255;
	_b = (unsigned int)(color->b * 255);
	if (_b > 255)
		_b = 255;
	_color = (0xFFu << 24) | (_r << 16) | (_g << 8) | _b;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = _color;
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

void free_canvas(t_canvas *canvas)
{
	if (canvas)
	{
		if (canvas->img.img)
		{
			mlx_destroy_image(canvas->mlx, canvas->img.img);
			canvas->img.img = NULL;
		}
		if (canvas->mlx_win)
		{
			mlx_destroy_window(canvas->mlx, canvas->mlx_win);
			canvas->mlx_win = NULL;
		}
		//if (canvas->mlx)
		//{
		//	mlx_loop_end(canvas->mlx);
		//	mlx_destroy_display(canvas->mlx);
		//	free(canvas->mlx);
		//}
		free(canvas);
	}
}



