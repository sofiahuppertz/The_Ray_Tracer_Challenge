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

void free_plane(void *p)
{
    t_plane *plane;

    plane = (t_plane *)p;
    if (!plane)
        return;
    free(plane);
}