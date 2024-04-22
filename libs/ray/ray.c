#include "ray.h"

t_ray *ray(t_tuple *origin, t_tuple *direction)
{
    t_ray *r;

    r = NULL;
    r = (t_ray *)calloc(1, sizeof(t_ray));
    if (!r)
    {
        printf("Error: ray memory allocation failed.\n");
        return NULL;
    }
    if (origin->w != 1.0)
        printf("Warning: ray origin is not a point.\n");
    if (direction->w != 0.0)
        printf("Warning: ray direction is not a vector.\n");
    r->o = origin;
    r->di = direction;
    r->tf.type = RAY;
    r->tf.transform = transform_ray;
    return r;
}

void transform_ray(void *ray, t_matrix *transformation)
{
    t_ray *r;
    t_matrix *t_copy;
    
    r = (t_ray *)ray;
    if (!transformation)
    {
        printf("Error: transform_ray: transformation matrix is NULL.\n");
        return;
    }
    t_copy = matrixcpy((const t_matrix)(*transformation));
    if (!t_copy)
    {
        free_matrix(&transformation);
        printf("Error: transform_ray: matrixcpy failed: couldn't tranform ray.\n");
        return;
    }
    transform((void *)r->o, transformation);
    transform((void *)r->di, t_copy);
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

t_ray *raycpy(const t_ray r)
{
    t_ray *cpy;
    t_tuple *origin;
    t_tuple *direction;

    origin = tuplecpy((const t_tuple)(*r.o));
    if (!origin)
    {
        printf("Error: raycpy: origin memory allocation failed.\n");
        return NULL;
    } 
    direction = tuplecpy((const t_tuple)(*r.di));
    if (!direction)
    {
        printf("Error: raycpy: direction memory allocation failed.\n");
        free(origin);
        return NULL;
    }
    cpy = ray(origin, direction);
    return cpy;
}