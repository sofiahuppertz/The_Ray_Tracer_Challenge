#include "plane.h"

void plane_normal_at(void *p, const t_tuple object_point, t_tuple **normal)
{
    (void)p;
    (void)object_point;
    if (!normal)
        return;
    *normal = vector(0, 1, 0);
}
void intersect_plane(void *p, const t_ray transformed_ray, t_intersection **xs)
{
    t_plane *plane;
    double t;

    plane = (t_plane *)p;

    if (fabs(transformed_ray.di->y) < EPSILON)
    {
        *xs = NULL;
        return;
    }
    t = -transformed_ray.o->y / transformed_ray.di->y;
    *xs = intersection(t, PLANE, (void *)plane);
}