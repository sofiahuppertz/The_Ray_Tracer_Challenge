#include "cylindrical.h"

void cyl( t_cyl *cyl)
{
    shape(CYLINDRICAL, (t_shape *)cyl); 
    cyl->shape.local_intersect = intersect_cyl;
    cyl->shape.local_normal_at = cyl_normal_at;
    cyl->o = point(0, 0, 0);
    if (!cyl->o)
    {
        printf("Error: cyl: point failed.\n");
        free(cyl);
        return;
    }
    cyl->max_y = INFINITY;
    cyl->min_y = -INFINITY;
    cyl->closed = 0;
}


void set_bounds(t_cyl *cyl, double min_y, double max_y)
{
    if (!cyl)
        return ;
    cyl->min_y = min_y;
    cyl->max_y = max_y;
}

void set_closed(t_cyl *cyl, int closed)
{
    if (!cyl)
        return ;
    cyl->closed = closed;
}
