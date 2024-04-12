#ifndef RAY_H
# define RAY_H

#include "../tuple/tuple.h"

typedef struct s_ray {
    t_tuple *o;
    t_tuple *di;
} t_ray;

t_ray *ray(t_tuple origin, t_tuple direction);

void print_ray(t_ray r);
void free_ray(t_ray *r);

t_tuple *position(t_ray r, double t);


#endif