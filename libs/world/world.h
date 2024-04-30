#ifndef WORLD_H
# define WORLD_H

#include "../light/light.h"
#include "../comps/comps.h"
#include "../sphere/sphere.h"

typedef struct s_world 
{
    t_point_light *light;
    t_shape *shapes;
} t_world;


// Constructors
t_world *default_world( void );
t_world *empty_world( void );

// Setters -ish
void set_shape(t_world *w, t_shape *new_shape);
void set_light(t_world *w, t_point_light *l);

// Other functions
t_intersection *intersect_world(const t_world w, const t_ray r);
t_color *color_at(const t_world w, const t_ray r, int remaining);
t_color *shade_hit(const t_world w, const t_comps comps, int remaining);
t_color *reflected_color(const t_world w, const t_comps comps, int remaining);
t_color *refracted_color(const t_world w, const t_comps comps, int remaining);
double schlick(const t_comps comps);
int is_shadowed(const t_world w, const t_tuple point);

// Free functions
void free_world(t_world **w);

#endif