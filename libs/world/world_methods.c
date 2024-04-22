#include "world.h"

void print_comps(t_comps *comps)
{
    printf("t: %f\n", comps->t);
    printf("object: %d\n", comps->object);
    printf("object_ptr: %p\n", comps->object_ptr);
    printf("point: ");
    print_tuple(comps->point);
    printf("over_point: ");
    print_tuple(comps->over_point);
    printf("eyev: ");
    print_tuple(comps->eyev);
    printf("normalv: ");
    print_tuple(comps->normalv);
    printf("inside: %d\n", comps->inside);
}

t_intersection *intersect_world(const t_world w, const t_ray r)
{
    t_intersection *xs;

    xs = intersect_shapes(w.shapes, r);
    return xs;
}


t_color *shade_hit(const t_world w, const t_comps comps)
{
    t_color *color;
    t_material *material;
    int shadowed;
    
    material = NULL;
    material = ((t_shape *)(comps.object_ptr))->material;
    shadowed = is_shadowed(w, *comps.over_point);
    color = lighting(*material, *w.light, *comps.over_point, *comps.eyev, *comps.normalv, shadowed);
    return color;
}

int is_shadowed(const t_world w, const t_tuple point)
{
    t_tuple *ray_direction;
    t_ray *r;
    t_intersection *xs;
    t_intersection *_hit;
    double distance;

    ray_direction = sub_tuple((const t_tuple)*w.light->position, point);
    distance = mag(*ray_direction);
    r = ray(tuplecpy(point), norm(ray_direction));
    xs = intersect_world(w, *r);
    _hit = hit(&xs);
    if (_hit && _hit->t < distance)
    {
        free_tuples(&ray_direction, NULL);
        free_intersections(&xs);
        return 1;
    }
    free_ray(&r);
    free_intersections(&xs);
    return 0;
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