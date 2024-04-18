#ifndef SPACE_H
# define SPACE_H

#include "../intersection/intersection.h"
#include "../light/light.h"
#include "../mlx_helpers/mlx_helpers.h"



typedef struct s_space
{
    t_point_light *light;
    t_tuple *view_point;
    double wall_z;
    double wall_size;
    double half;
} t_space;

void draw_sphere(const t_space space, t_canvas *canvas, const t_sphere sp);

#endif