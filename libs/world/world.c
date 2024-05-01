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
    m = default_material();
    set_pattern(m, solid(color(0.8, 1.0, 0.6)));
    set_ambient(m, 0.1);
    set_diffuse(m, 0.7);
    set_specular(m, 0.2);
    set_shininess(m, 200.0);
    set_material(&s1->shape, m);
    t_sphere *s2 = sphere();
    if (!s2)
    {
        free_world(&w);
        return NULL;
    }
    transform((void *)&s2->shape,  scaling(0.5, 0.5, 0.5));

    set_shape(w, (t_shape *)&s1->shape);
    set_shape(w, (t_shape *)&s2->shape);
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



