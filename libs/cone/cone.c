#include "cone.h"

t_cone *cone( void )
{
    t_cone *cone;

    cone = (t_cone *)calloc(1, sizeof(t_cone));
    if (!cone)
    {
        printf("Error: cone: calloc failed.\n");
        return NULL;
    }
    cyl(&cone->c);
    cone->c.local_calc_disc = disc_cone;
    cone->c.local_check_cap = cone_check_cap;
    cone->c.local_cyl_normal = cone_normal;
    return cone;
}


void free_cone(void *s)
{
    t_cone *cone;

    cone = (t_cone *)s;
    if (!cone)
        return ;
    free(cone->c.o);
    free(cone);
}

void cone_normal(t_tuple object_point, t_tuple **normal)
{
    double y;
    
    y = sqrt(pow(object_point.x, 2) + pow(object_point.z, 2));
    if (object_point.y > 0)
        y = -y;
    *normal = vector(object_point.x, y, object_point.z);
}