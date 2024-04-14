#include "sphere.h"

t_sphere *sphere( void )
{
    t_sphere *s = NULL;
    static int sp_id = 0;
    
    s = (t_sphere *)calloc(sizeof(t_sphere), 1);
    if (!s)
        return NULL;
    s->o = point(0, 0, 0);
    if (!s->o)
    {
        free(s);
        return NULL;
    }
    s->radius = 1;
    s->id = sp_id++;
    s->transform = identity(4);
    if (!s->transform)
    {
        free(s->o);
        free(s);
        return NULL;
    }
    return s;
}


void print_sphere( const t_sphere *s )
{
    printf("Sphere %d\n", s->id);
    printf("Origin: ");
    print_tuple((const t_tuple *)(s->o));
    printf("Radius: %f\n", s->radius);
    printf("Transform:\n");
    print_matrix((const t_matrix *)(s->transform));
}

void free_sphere( t_sphere **s )
{
    t_sphere *ptr;

    ptr = *s;
    free(ptr->o);
    ptr->o = NULL;
    free_matrix(&(ptr->transform));
    ptr->transform = NULL;
    free(ptr);
    ptr = NULL;
}

void set_transform(t_sphere *s, t_matrix *transformation)
{
    if (s->transform)
        free_matrix(&s->transform);
    s->transform = transformation;
}