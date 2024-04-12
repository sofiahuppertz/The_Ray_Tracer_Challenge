#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H


#include "../../minilibx/mlx.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_pixel(t_data *data, int x, int y, int color);


#endif