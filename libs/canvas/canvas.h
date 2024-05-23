/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:13 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 13:26:48 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "../../minilibx/mlx.h"
# include "../color/color.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_canvas
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
}			t_canvas;

typedef struct s_coordinates
{
	double	x;
	double	y;
}			t_coordinates;

void		draw_pixel(t_data *data, int x, int y, const t_color *color);
t_canvas	*canvas(int width, int height);
void		free_canvas(t_canvas *canvas);

#endif