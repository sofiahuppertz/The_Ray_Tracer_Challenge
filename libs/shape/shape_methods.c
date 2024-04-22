
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


t_tuple *normal_at(t_shape *shape, const t_tuple world_point)
{
    t_tuple *normal;
    t_tuple *object_point;
    t_matrix *tr;

    if (!shape)
    {
        printf("Error: normal_at: NULL pointer.\n");
        return NULL;
    }
    // transform world_point to object_point
    object_point = tuplecpy(world_point);
    transform((void *)object_point, inverse(*shape->tr));
    if (shape->tf.type == SHAPE)
    {
        printf("Error: normal_at: abstract type.\n");
        return NULL;
    }
    // call local_normal_at
    normal = NULL;
    shape->local_normal_at((void *)shape, *object_point, &normal);
    if (!normal)
        return NULL;
    //transform normal by inverse of the transpose and normalize
    tr = inverse(*shape->tr);
    transform_tuple(normal, transpose(&tr));
    normal->w = 0;
    return norm(normal);
}