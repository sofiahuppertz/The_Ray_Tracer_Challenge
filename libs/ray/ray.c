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

t_ray *transform_ray(const t_ray r, t_matrix *transformation)
{
    t_ray *new_ray;
    t_tuple *new_origin;
    t_tuple *new_direction;
    t_matrix *t;
    
    if (!transformation)
    {
        printf("Error: transform_ray: transformation matrix is NULL.\n");
        return NULL;
    }
    new_origin = tuplecpy((const t_tuple)(*r.o));
    if (!new_origin)
        return NULL;
    t = matrixcpy((const t_matrix)(*transformation));
    transform_tuple(new_origin, transformation);
    new_direction = tuplecpy((const t_tuple)(*r.di));
    if (!new_direction)
    {
        free(new_origin);
        return NULL;
    }
    transform_tuple(new_direction, t);
    new_ray = ray((const t_tuple)(*new_origin), (const t_tuple)(*new_direction));
    free(new_origin);
    free(new_direction);
    return new_ray;
}


void print_ray(const t_ray *r)
{
    printf("Ray origin:\n");
    print_tuple((const t_tuple*)(r->o));
    printf("Ray direction:\n");
    print_tuple((const t_tuple*)(r->di));

}

t_tuple *position(const t_ray r, const double t)
{
    t_tuple *position;
    t_tuple *temp;

    temp = tuplecpy((const t_tuple)(*r.di));
    scalar_tuple(temp, t);
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

void free_ray(t_ray **r)
{
    if ((*r)->o) {
        free((void *)(*r)->o);
        (*r)->o = NULL;
    }
    if ((*r)->di) {
        free((void *)(*r)->di);
        (*r)->di = NULL;
    }
    free((void *)*r);
    *r = NULL;
}