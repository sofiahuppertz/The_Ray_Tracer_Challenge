#include "ray.h"

t_ray *ray(const t_tuple origin, const t_tuple direction)
{
    t_ray *r;

    r = (t_ray *)calloc(1, sizeof(t_ray));
    if (!r)
    {
        printf("Error: ray memory allocation failed.\n");
        return NULL;
    }
    if (origin.w != 1.0)
        printf("Error: ray origin is not a point.\n");
    if (direction.w != 0.0)
        printf("Error: ray direction is not a vector.\n");
    r->o = point(origin.x, origin.y, origin.z);
    r->di = vector(direction.x, direction.y, direction.z);
    return r;
}

void print_ray(const t_ray r)
{
    printf("Ray origin:\n");
    print_tuple((const t_tuple)(*r.o));
    printf("Ray direction:\n");
    print_tuple((const t_tuple)(*r.di));

}

t_tuple *position(const t_ray r, const double t)
{
    t_tuple *position;
    t_tuple *temp;

    temp = scalar_tuple((const t_tuple)(*r.di), t);
    if (!temp)
    {
        printf("Error: position memory allocation failed.\n");
        return NULL;
    }
    position = add_tuple((const t_tuple)(*r.o), (const t_tuple)(*temp));
    if (!position)
    {
        printf("Error: position memory allocation failed.\n");
        return NULL;
    }
    free(temp);
    return position;
}

void free_ray(t_ray *r)
{
    free(r->o);
    r->o = NULL;
    free(r->di);
    r->di = NULL;
    free(r);
    r = NULL;
}