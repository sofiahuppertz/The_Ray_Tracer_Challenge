#ifndef SPHERE_H
# define SPHERE_H

#include "../tuple/tuple.h"
#include "../matrix/matrix.h"

#include "stdlib.h"

typedef struct s_sphere {
    int id;
    t_tuple *o;
    t_matrix *transform;
    double radius;
} t_sphere;

t_sphere *sphere( void );

void set_transform(t_sphere *s, t_matrix *transformation);
void print_sphere(const t_sphere *s);
void free_sphere(t_sphere **s);


#endif