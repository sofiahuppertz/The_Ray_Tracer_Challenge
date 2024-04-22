#ifndef SPHERE_H
# define SPHERE_H

#include "../tuple/tuple.h"
#include "../shape/shape.h"

#include "stdlib.h"

typedef struct s_sphere {
    t_shape shape;
    t_tuple *o;
    double radius;
} t_sphere;


// Constructors destructors
t_sphere *sphere( void );
void free_sphere(void *s);
void print_sphere(void *s);


// Methods
t_tuple *normal_at(const t_sphere s, const t_tuple world_point);
void intersect_sphere(void *s, const t_ray transformed_ray, t_intersection **xs);


#endif