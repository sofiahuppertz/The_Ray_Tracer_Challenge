#ifndef CYLINDRICAL_H
#define CYLINDRICAL_H

#include "../shape/shape.h"

typedef double (*calc_disc)(void *cyl, const t_ray ray, t_intersection **_xs, double *a, double *b);
typedef int (*check_cap)(const t_ray r, double t, double y);
typedef void (*cyl_normal)(const t_tuple object_point, t_tuple **normal);

typedef struct s_cyl {
    t_shape shape;
    t_tuple *o;
    double max_y;
    double min_y;
    int closed;
    calc_disc local_calc_disc;
    check_cap local_check_cap;
    cyl_normal local_cyl_normal;

} t_cyl;

// Constructor
void cyl( t_cyl *cyl);

//Methods
void cyl_normal_at(void *s, const t_tuple object_point, t_tuple **normal);
void intersect_cyl(void *s, const t_ray transformed_ray, t_intersection **xs);
void intersect_caps(t_cyl *cyl, const t_ray r, t_intersection **_xs);

//Setters
void set_bounds(t_cyl *cyl, double min_y, double max_y);
void set_closed(t_cyl *cyl, int closed);


# endif