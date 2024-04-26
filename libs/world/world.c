#include "world.h"


t_world *empty_world( void )
{
    t_world *w;

    w = (t_world *)calloc(sizeof(t_world), 1);
    if (!w)
        return NULL;
    return w;
}

t_world *default_world( void )
{
    t_world *w;
    t_material *m;

    w = (t_world *)calloc(sizeof(t_world), 1);
    if (!w)
        return NULL;
    w->light = point_light(color(1, 1, 1), point(-10, 10, -10));
    t_sphere *s1 = sphere();
    if (!s1)
    {
        free_world(&w);
        return NULL;
    }
    m = material(solid(color(0.8, 1.0, 0.6)), 0.1, 0.7, 0.2, 200.0);
    set_material(&s1->shape, m);
    set_shape(w, (t_shape *)s1);
    t_sphere *s2 = sphere();
    if (!s2)
    {
        free_world(&w);
        return NULL;
    }
    transform((void *)s2,  scaling(0.5, 0.5, 0.5));
    set_shape(w, (t_shape *)s2);
    return w;
}

void set_shape(t_world *w, t_shape *new_shape)
{
    t_shape *w_shapes;

    if (!w || !new_shape)
    {
        printf("Error: set_shape: NULL parameter.\n");
        return;
    }
    if (!w->shapes)
    {
        w->shapes = new_shape;
        return;
    }
    w_shapes = w->shapes;
    while (w_shapes->next)
        w_shapes = w_shapes->next;
    w_shapes->next = new_shape;
}

void free_world(t_world **w)
{
    t_world *ptr;

    ptr = *w;
    free_point_light(&(ptr->light));
    free_shape(ptr->shapes);
    free(ptr);
    ptr = NULL;
    *w = NULL;
}



t_comps *prepare_computations(const t_intersection i, const t_ray r)
{
    t_comps *comps;
    t_tuple *normalv_cpy;

    comps = (t_comps *)calloc(sizeof(t_comps), 1);
    if (!comps)
    {
        printf("Error: prepare_computations: calloc failed.\n");
        return NULL;
    }
    comps->t = i.t;
    comps->object = i.object;
    comps->object_ptr = (t_shape *)i.object_ptr;
    comps->point = position(r, comps->t);
    comps->eyev = tuplecpy((const t_tuple)(*r.di));
    neg_tuple(comps->eyev);
    comps->normalv = normal_at((t_shape *)i.object_ptr, *comps->point);
    if (dot(*comps->normalv, *comps->eyev) < 0)
    {
        comps->inside = 1;
        neg_tuple(comps->normalv);
    }
    else
        comps->inside = 0;
    normalv_cpy = tuplecpy(*comps->normalv);
    scalar_tuple(normalv_cpy, EPSILON);
    comps->over_point = add_tuple(*comps->point, *normalv_cpy);
    free(normalv_cpy);
    return comps;
}


void free_comps(t_comps **comps)
{
    t_comps *ptr;

    ptr = *comps;
    free(ptr->point);
    free(ptr->eyev);
    free(ptr->normalv);
    free(ptr->over_point);
    free(ptr);
    ptr = NULL;
    *comps = NULL;
}





void set_light(t_world *w, t_point_light *l)
{
    if (!w || !l)
    {
        printf("Error: set_light: NULL parameter.\n");
        return;
    }
    free_point_light(&(w->light));
    w->light = l;
}



