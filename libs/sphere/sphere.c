#include "sphere.h"

t_sphere *sphere( void )
{
    t_sphere *sphere = NULL;
    
    sphere = (t_sphere *)calloc(sizeof(t_sphere), 1);
    if (!sphere)
    {
        printf("Error: sphere: calloc failed.\n");
        return NULL;
    }
    shape(SPHERE, &(sphere->shape));
    sphere->shape.local_intersect = intersect_sphere;
    sphere->shape.local_normal_at = sphere_normal_at;
    sphere->shape.local_free = free_sphere;
    sphere->shape.local_print = print_sphere;
    sphere->o = point(0, 0, 0);
    if (!sphere->o)
    {
        printf("Error: sphere: point failed.\n");
        free(sphere);
        return NULL;
    }
    sphere->radius = 1;
    return sphere;
}


void print_sphere( void *s )
{
    const t_sphere *sphere;

    sphere = (const t_sphere *)s;
    printf("Sphere %d\n", sphere->shape.id);
    printf("Origin: ");
    print_tuple((const t_tuple *)(sphere->o));
    printf("Radius: %f\n", sphere->radius);
    printf("Transform:\n");
    print_matrix((const t_matrix *)(sphere->shape.tr));
    printf("Material:\n");
    print_material((const t_material)*(sphere->shape.material));
}

void free_sphere(void *s)
{
    t_sphere *sphere;

    sphere = (t_sphere *)s;
    if (!sphere)
        return ;
    free(sphere->o);
    free(sphere);
}


t_sphere *glass_sphere( void )
{
    t_sphere *s;

    s = sphere();
    if (!s)
    {
        printf("Error: glass_sphere: sphere failed.\n");
        return NULL;
    }
    s->shape.material->transparency = 1.0;
    s->shape.material->refrac_index = 1.5;
    return s;
}