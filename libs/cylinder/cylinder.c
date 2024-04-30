#include "cylinder.h"

t_cylinder *cylinder( void )
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)calloc(1, sizeof(t_cylinder));
    if (!cylinder)
    {
        printf("Error: cylinder: calloc failed.\n");
        return NULL;
    }
    shape(CYLINDER, (t_shape *)cylinder);
    cylinder->shape.local_intersect = intersect_cylinder;
    cylinder->shape.local_normal_at = cylinder_normal_at;
    cylinder->shape.local_free = free_cylinder;
    cylinder->shape.local_print = print_cylinder;
    cylinder->o = point(0, 0, 0);
    if (!cylinder->o)
    {
        printf("Error: cylinder: point failed.\n");
        free(cylinder);
        return NULL;
    }
    cylinder->radius = 1;
    cylinder->max_y = INFINITY;
    cylinder->min_y = -INFINITY;
    cylinder->closed = 0;
    return cylinder;
}

void free_cylinder(void *s)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)s;
    if (!cylinder)
        return ;
    free(cylinder->o);
    free(cylinder);
}


void set_bounds(t_cylinder *cyl, double min_y, double max_y)
{
    if (!cyl)
        return ;
    cyl->min_y = min_y;
    cyl->max_y = max_y;
}

void set_closed(t_cylinder *cyl, int closed)
{
    if (!cyl)
        return ;
    cyl->closed = closed;
}