#ifndef SPHERE_H
# define SPHERE_H

#include "../light/light.h"
#include "../matrix/matrix.h"

#include "stdlib.h"

typedef struct s_sphere {
    int id;
    double radius;
    t_tuple *o;
    t_matrix *transform;
    t_material *material;
    struct s_sphere *next;
} t_sphere;


// Constructors destructors
t_sphere *sphere( void );
void free_sphere(t_sphere **s);
void print_sphere(const t_sphere *s);

//Setter
void set_transform(t_sphere *s, t_matrix *transformation);
void set_material(t_sphere *s, t_material *m);

// Other functions
t_tuple *normal_at(const t_sphere s, const t_tuple world_point);


#endif