#ifndef WORLD_H
# define WORLD_H

#include "../light/light.h"
#include "../intersection/intersection.h"

typedef struct s_world 
{
    t_point_light *light;
    t_sphere *spheres;
} t_world;

typedef struct s_comps
{
    double t;
    t_object object;
    void *object_ptr;
    t_tuple *point;
    t_tuple *eyev;
    t_tuple *normalv;
    int inside;
} t_comps;

t_world *default_world( void );
void free_world(t_world **w);

void add_sphere_to_world(t_world *w, t_sphere *s);

t_comps *prepare_computations(const t_intersection i, const t_ray r);
t_color *shade_hit(const t_world w, const t_comps comps);
void print_comps(t_comps *comps);
void free_comps(t_comps **comps);
t_intersection *intersect_world(const t_world w, const t_ray r);


#endif