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
    cyl(&cylinder->c);
    cylinder->radius = 1;
    cylinder->c.shape.local_print = print_cylinder;
    cylinder->c.shape.local_free = free_cylinder;
    cylinder->c.local_calc_disc = disc_cylinder;
    cylinder->c.local_check_cap = cylinder_check_cap;
    cylinder->c.local_cyl_normal = cylinder_normal;
    return cylinder;
}

void free_cylinder(void *s)
{
    t_cylinder *cylinder;

    cylinder = (t_cylinder *)s;
    if (!cylinder)
        return ;
    free(cylinder->c.o);
    free(cylinder);
}


