#include "world.h"

static t_intersection *shadow_casting_hit(t_intersection **xs)
{
    t_intersection *hit;
    t_shape *shape;

    if (!xs || !(*xs))
        return NULL;
    hit = *xs;
    while (hit) 
    {
        if (hit && hit->t >= 0)
        {
            shape = (t_shape *)hit->object_ptr;
            if (shape->can_cast_shadow)
                return hit;
        }
        hit = hit->next;
    }
    return NULL;
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
    r = ray(tuplecpy(point), ray_direction);
    xs = intersect_world(w, *r);
    _hit = shadow_casting_hit(&xs);
    if (_hit && _hit->t < distance)
    {
        
        free_ray(&r);
        free_intersections(&xs);
        return 1;
    }
    free_ray(&r);
    free_intersections(&xs);
    return 0;
}
