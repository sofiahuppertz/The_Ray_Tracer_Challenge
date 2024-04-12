#ifndef SPHERE_H
# define SPHERE_H

#include "../tuple/tuple.h"

#include "stdlib.h"

typedef struct s_sphere {
    int id;
    t_tuple *o;
    double radius;
} t_sphere;

t_sphere *sphere( void );

void print_sphere(t_sphere s);
void free_sphere(t_sphere *s);


#endif