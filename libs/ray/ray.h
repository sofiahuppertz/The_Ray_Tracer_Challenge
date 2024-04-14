#ifndef RAY_H
# define RAY_H

#include "../tuple/tuple.h"
#include "../matrix/matrix.h"

typedef struct s_ray {
    t_tuple const *o;
    t_tuple const *di;
} t_ray;

t_ray *ray(const t_tuple origin, const t_tuple direction);
t_ray *transform_ray(const t_ray r, const t_matrix transformation);

void print_ray(const t_ray *r);
void free_ray(t_ray **r);

t_tuple *position(t_ray r, double t);


#endif