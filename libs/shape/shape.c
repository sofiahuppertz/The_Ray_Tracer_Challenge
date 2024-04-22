
#include "shape.h"

t_shape *abstract_shape( void )
{
    static int id = 0;
    t_shape *shape;

    shape = (t_shape *)calloc(sizeof(t_shape), 1);
    if (!shape)
    {
        printf("Error: shape: calloc failed.\n");
        return NULL;
    }
    shape->id = id++;
    shape->tf.type = SHAPE;
    shape->tf.transform = set_transform;
    shape->material = default_material();
    if (!shape->material)
    {
        printf("Error: shape: default_material failed.\n");
        free(shape);
        return NULL;
    }
    shape->tr = identity(4);
    {
        if (!shape->tr)
        {
            printf("Error: shape: identity failed.\n");
            free(shape->material);
            free(shape);
            return NULL;
        }
    }
    shape->next = NULL;
    return shape;
}


void shape( t_elem type , t_shape *shape)
{
    static int id = 0;

    shape->id = id++;
    shape->tf.type = type;
    shape->tf.transform = set_transform;
    shape->material = default_material();
    if (!shape->material)
    {
        printf("Error: shape: default_material failed.\n");
        return;
    }
    shape->tr = identity(4);
    if (!shape->tr)
    {
        printf("Error: shape: identity failed.\n");
        free(shape->material);
        return;
    }
    shape->next = NULL;
}

void set_transform(void *s, t_matrix *transformation)
{
    t_shape *shape;

    shape = (t_shape *)s;
    if (!shape || !transformation)
    {
        printf("Error: set_transform: NULL pointer.\n");
        return;
    }
    if (shape->tr)
        free_matrix(&shape->tr);
    shape->tr = transformation;
}

void set_material(t_shape *shape, t_material *material)
{
    if (!shape || !material)
    {
        printf("Error: set_material: NULL pointer.\n");
        return;
    }
    if (shape->material)
        free_material(&shape->material);
    shape->material = material;
}

void free_shape(t_shape *shape_list)
{
    t_shape *curr_shape;
    t_shape *next_shape;

    curr_shape = shape_list;
    while (curr_shape)
    {
        next_shape = curr_shape->next;
        free_material(&curr_shape->material);
        free_matrix(&curr_shape->tr);
        curr_shape->local_free((void *)curr_shape);
        curr_shape = next_shape;
    }
}
