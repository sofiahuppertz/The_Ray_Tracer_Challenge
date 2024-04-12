#include "sphere.h"

t_sphere *sphere( void )
{
    t_sphere *s;
    static int sp_id = 0;
    
    s = (t_sphere *)calloc(sizeof(t_sphere), 1);
    if (!s)
    {
        printf("Error: could not allocate memory for sphere\n");
        return NULL;
    }
    s->o = point(0, 0, 0);
    if (!s->o)
    {
        printf("Error: could not allocate memory for sphere origin\n");
        free(s);
        return NULL;
    }
    s->radius = 1;
    s->id = sp_id;
    sp_id++;
    return s;
}


void print_sphere( t_sphere s )
{
    printf("Sphere %d\n", s.id);
    printf("Origin: ");
    print_tuple((const t_tuple)(*s.o));
    printf("Radius: %f\n", s.radius);
}

void free_sphere( t_sphere *s )
{
    free(s->o);
    s->o = NULL;
    free(s);
    s = NULL;
}