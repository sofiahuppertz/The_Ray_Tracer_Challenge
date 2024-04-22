#ifndef INTERSECTION_H
# define INTERSECTION_H

#include <stdarg.h>

#include "../tuple/tuple.h"
#include "../ray/ray.h"


typedef struct s_intersection
{
    double t;
    t_elem object;
    void *object_ptr;
    struct s_intersection *next;
} t_intersection;


// Constructors
t_intersection *intersection(const double t, const t_elem object, void *object_ptr);
t_intersection *intersections(t_intersection *initial, ...);
t_intersection *merge_sorted(t_intersection **first, t_intersection **next);


// Methods
t_intersection *hit(t_intersection **xs);
int count_intersections(t_intersection *xs);
void print_intersections(const t_intersection *i);

// ???
t_tuple *position_at(const double t, const t_ray r);

// Destructors
void free_intersections(t_intersection **initial);

#endif
