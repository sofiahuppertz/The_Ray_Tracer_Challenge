#include "plane.h"

t_plane *plane( void )
{
    t_plane *plane;

    plane = (t_plane *)calloc(1, sizeof(t_plane));
    if (!plane)
    {
        printf("Error: plane: calloc failed\n");
        return (NULL);
    }
    shape( PLANE , &(plane->shape));
    plane->shape.local_intersect = intersect_plane;
    plane->shape.local_normal_at = plane_normal_at;;
    plane->shape.local_print = print_plane;
    plane->shape.local_free = free_plane;
    return (plane);
}

t_matrix *find_rotation_matrix(const t_tuple normal)
{
    t_tuple *object_normal;
    double dot_product;
    double rotation_angle;
    
    object_normal = vector(0, 1, 0);
    dot_product = dot(*object_normal, normal);
    if (dot_product == 1)
    {
        free(object_normal);
        return identity(4);
    }
    rotation_angle = acos(dot_product);
    t_tuple *axis = cross(normal, *object_normal);
    free(object_normal);
    return rotation_matrix(rotation_angle, axis->x, axis->y, axis->z);
}

void free_plane(void *p)
{
    t_plane *plane;

    plane = (t_plane *)p;
    if (!plane)
        return;
    free(plane);
}
