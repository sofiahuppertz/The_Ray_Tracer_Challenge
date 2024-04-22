#ifndef SHAPE_H
# define SHAPE_H

#include "../matrix/matrix.h"
#include "../light/light.h"
#include "../intersection/intersection.h"


typedef void (*t_local_intersect)(void *shape, t_ray ray, t_intersection **xs);
typedef void (*t_local_free)(void *shape);
typedef void (*t_local_print)(void *shape);

typedef struct s_shape
{
    t_tf tf;
    int id;
    t_material *material;
    t_local_intersect local_intersect;
    t_local_free local_free;
    t_local_print local_print;
    t_matrix *tr;
    struct s_shape *next;
} t_shape;


// Constructors
t_shape *abstract_shape(void);
void shape(t_elem type, t_shape *shape);

// Setters
void set_transform(void *s, t_matrix *transformation);
void set_material(t_shape *shape, t_material *material);

// Methods
t_intersection *intersect(const t_shape *shape, const t_ray ray, t_elem type);
t_intersection *intersect_shapes(t_shape *shapes, const t_ray ray);
void print_shapes(t_shape *shapes);

// Destructors
void free_shape(t_shape *s);


#endif