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
    m = material(color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2, 200.0);
    set_material(s1, m);
    add_sphere_to_world(w, s1);
    t_sphere *s2 = sphere();
    if (!s2)
    {
        free_world(&w);
        return NULL;
    }
    set_transform(SPHERE, (void *)s2,  scaling(0.5, 0.5, 0.5));
    add_sphere_to_world(w, s2);
    return w;
}

void add_sphere_to_world(t_world *w, t_sphere *s)
{
    t_sphere *ptr;

    if (!w || !s)
    {
        printf("Error: add_sphere_to_world: NULL parameter.\n");
        return;
    }
    if (!w->spheres)
    {
        w->spheres = s;
        return;
    }
    ptr = w->spheres;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = s;
}

void free_world(t_world **w)
{
    t_world *ptr;

    ptr = *w;
    free_point_light(&(ptr->light));
    free_sphere(&(ptr->spheres));
    free(ptr);
    ptr = NULL;
    *w = NULL;
}

t_intersection *intersect_world(const t_world w, const t_ray r)
{
    t_intersection *xs;

    xs = multiple_i_ray_sphere(w.spheres, r);
    return xs;
}


t_comps *prepare_computations(const t_intersection i, const t_ray r)
{
    t_comps *comps;

    comps = (t_comps *)calloc(sizeof(t_comps), 1);
    if (!comps)
    {
        printf("Error: prepare_computations: calloc failed.\n");
        return NULL;
    }
    comps->t = i.t;
    comps->object = i.object;
    comps->object_ptr = i.object_ptr;
    comps->point = position(r, comps->t);
    comps->eyev = tuplecpy((const t_tuple)(*r.di));
    neg_tuple(comps->eyev);
    if (comps->object == SPHERE)
        comps->normalv = normal_at(*(t_sphere *)i.object_ptr, *comps->point);
    if (dot(*comps->normalv, *comps->eyev) < 0)
    {
        comps->inside = 1;
        neg_tuple(comps->normalv);
    }
    else
        comps->inside = 0;
    return comps;
}

void print_comps(t_comps *comps)
{
    printf("t: %f\n", comps->t);
    printf("object: %d\n", comps->object);
    printf("object_ptr: %p\n", comps->object_ptr);
    if (comps->object == SPHERE)
    {
        printf("sphere: ");
        print_sphere((t_sphere *)comps->object_ptr);
    }
    printf("point: ");
    print_tuple(comps->point);
    printf("eyev: ");
    print_tuple(comps->eyev);
    printf("normalv: ");
    print_tuple(comps->normalv);
    printf("inside: %d\n", comps->inside);
}

void free_comps(t_comps **comps)
{
    t_comps *ptr;

    ptr = *comps;
    free(ptr->point);
    free(ptr->eyev);
    free(ptr->normalv);
    free(ptr);
    ptr = NULL;
    *comps = NULL;
}


t_color *shade_hit(const t_world w, const t_comps comps)
{
    t_color *color;
    t_material *material;
    
    material = NULL;
    if (comps.object == SPHERE)
        material = ((t_sphere *)comps.object_ptr)->material;
    color = lighting(*material, *w.light, *comps.point, *comps.eyev, *comps.normalv);
    return color;
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

t_color *color_at(const t_world w, const t_ray r)
{
    t_intersection *xs;
    t_intersection *_hit;
    t_comps *comps;
    t_color *c;

    xs = intersect_world(w, r);
    _hit = hit(&xs);
    if (!_hit)
    {
        free_intersections(&xs);
        return black();
    }
    comps = prepare_computations(*_hit, r);
    c = shade_hit(w, *comps);
    free_comps(&comps);
    free_intersections(&xs);
    return c;
}