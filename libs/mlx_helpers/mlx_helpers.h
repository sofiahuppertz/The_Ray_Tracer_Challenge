#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H


#include "../../minilibx/mlx.h"
#include "../color/color.h"

#include <stdio.h>
#include <stdlib.h>


#define CANVAS_PIXELS 100


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_canvas {
	t_data img;
	void *mlx;
	void *mlx_win;
	double pixel_size;
} t_canvas;

typedef struct s_coordinates {
	int x;
	int y;
} t_coordinates;

void	draw_pixel(t_data *data, int x, int y, const t_color *color);
t_canvas *canvas(int width, int height, double wall_size);

#endif