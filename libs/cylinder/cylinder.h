#ifndef CYLINDER_H
#define CYLINDER_H

#include "../cylindrical/cylindrical.h"

typedef struct s_cylinder {
    t_cyl c;
    double radius;

} t_cylinder;


t_cylinder *cylinder( void );
void free_cylinder(void *s);

//methods
void print_cylinder(void *s);
double disc_cylinder(void *cyl, const t_ray ray, t_intersection **_xs, double *a, double *b);
int cylinder_check_cap(const t_ray r, double t, double y);
void cylinder_normal(const t_tuple object_point, t_tuple **normal);



#endif