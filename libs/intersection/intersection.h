#ifndef INTERSECTION_H
# define INTERSECTION_H

#include "../ray/ray.h"
#include "../sphere/sphere.h"
#include "../tuple/tuple.h"

typedef enum e_object
{
    SPHERE
} t_object;

typedef struct s_intersection
{
    double t;
    t_object object;
    t_intersection *next;
} t_intersection;

t_intersection **i_ray_sphere(const t_sphere s, const t_ray r);
t_intersection *intersection(const double t, const t_object object);

t_intersection *hit(t_intersection **xs);

int count_solutions(t_intersection **xs);

#endif