#ifndef CYLINDER_H
#define CYLINDER_H

#include "../shape/shape.h"

typedef struct s_cylinder {
    t_shape shape;
    t_tuple *o;
    double radius;
    double max_y;
    double min_y;
    int closed;
} t_cylinder;


t_cylinder *cylinder( void );
void free_cylinder(void *s);

//methods
void print_cylinder(void *s);
void cylinder_normal_at(void *s, const t_tuple object_point, t_tuple **normal);
void intersect_cylinder(void *s, const t_ray transformed_ray, t_intersection **xs);

void set_bounds(t_cylinder *cyl, double min_y, double max_y);
void set_closed(t_cylinder *cyl, int closed);


#endif