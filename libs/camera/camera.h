#ifndef CAMERA_H
#define CAMERA_H

#include "../matrix/matrix.h"
#include "../ray/ray.h"
#include "../mlx_helpers/mlx_helpers.h"
#include "../world/world.h"

typedef struct s_camera
{
    t_tf tf;
    double hsize;
    double vsize;
    double half_width;
    double half_height;
    double field_of_view;
    double pixel_size;
    t_matrix *vt;
} t_camera;

// Constructors
t_matrix *view_transformation(t_tuple *from, t_tuple *to, t_tuple *up);
t_camera *camera(double hsize, double vsize, double field_of_view);
void pixel_size(t_camera *c);

// Operations
t_ray *ray_for_pixel(t_camera *c, double pixel_x, double pixel_y);
void transform_camera(void *c, t_matrix *vt);
t_canvas *render(t_camera *c, t_world *w);
void print_camera(const t_camera *c);
t_color *pixel_at(t_canvas *c, int x, int y);

// Destructors
void free_camera(t_camera **c);

#endif