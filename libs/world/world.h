#ifndef WORLD_H
# define WORLD_H

#include "../light/light.h"
#include "../sphere/sphere.h"

typedef struct s_world 
{
    t_point_light *light;
    t_shape *shapes;
} t_world;

typedef struct s_comps
{
    double t;
    t_elem object;
    t_shape *object_ptr;
    t_tuple *point;
    t_tuple *eyev;
    t_tuple *normalv;
    t_tuple *over_point;
    t_tuple *reflectv;
    int inside;
} t_comps;

// Constructors
t_world *default_world( void );
t_world *empty_world( void );
t_comps *prepare_computations(const t_intersection i, const t_ray r);

// Setters -ish
void set_shape(t_world *w, t_shape *new_shape);
void set_light(t_world *w, t_point_light *l);

// Other functions
t_intersection *intersect_world(const t_world w, const t_ray r);
t_color *color_at(const t_world w, const t_ray r, int remaining);
t_color *shade_hit(const t_world w, const t_comps comps, int remaining);
int is_shadowed(const t_world w, const t_tuple point);
t_color *reflected_color(const t_world w, const t_comps comps, int remaining);


void print_comps(t_comps *comps);

// Free functions
void free_world(t_world **w);
void free_comps(t_comps **comps);

#endif