
#include "shape.h"

void print_shapes(t_shape *shapes)
{
    t_shape *curr_shape;

    curr_shape = shapes;
    while (curr_shape)
    {
        curr_shape->local_print((void *)curr_shape);
        curr_shape = curr_shape->next;
    }
}

t_intersection *intersect(const t_shape *shape, const t_ray ray, t_elem type)
{
    t_intersection *xs;
    t_ray *transformed_ray;

    xs = NULL;
    // transform ray
    transformed_ray = raycpy(ray);
    if (!transformed_ray)
        return NULL;
    transform((void *)transformed_ray, inverse(*shape->tr));
    // check if shape is concrete
    if (type <= SHAPE)
    {
        printf("Interset: incorrect type.\n");
        return NULL;
    }
    // call local_intersect
    //shape->local_print((void *)shape);
    shape->local_intersect((void *)shape, *transformed_ray, &xs);
    free_ray(&transformed_ray);
    return xs;
}

t_intersection *intersect_shapes(t_shape *shapes, const t_ray ray)
{
    t_shape *curr_shape;
    t_intersection *tmp_xs;
    t_intersection *final_xs;

    curr_shape = shapes;
    final_xs = NULL;
    tmp_xs = NULL;
    while (curr_shape)
    {
        tmp_xs = intersect(curr_shape, ray, curr_shape->tf.type);
        final_xs = merge_sorted(&final_xs, &tmp_xs);
        curr_shape = curr_shape->next;
    }
    return final_xs;
}