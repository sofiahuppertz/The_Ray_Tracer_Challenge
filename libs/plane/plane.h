#ifndef PLANE_H
#define PLANE_H

#include "../shape/shape.h"

typedef struct s_plane
{
    t_shape shape;

} t_plane;

t_plane *plane(void);

void plane_normal_at(void *p, const t_tuple object_point, t_tuple **normal);
void intersect_plane(void *p, const t_ray transformed_ray, t_intersection **xs);

void free_plane(void *p);

#endif
