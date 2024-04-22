#include "sphere.h"

void sphere_normal_at(void *s, const t_tuple object_point, t_tuple **normal)
{
    t_sphere *sphere;

    sphere = (t_sphere *)s;
    *normal = sub_tuple(object_point, *sphere->o);
    if (!*normal)
    {
        printf("Error: sphere_normal_at: operation failed.\n");
        *normal = NULL;
    }
}


static double calculate_discriminant(double *a, double *b, double *c, const t_ray r, const t_tuple s_o)
{
    t_tuple *sphere_to_ray;
    double d;

    sphere_to_ray = sub_tuple((*r.o), s_o);
    *a = dot((*r.di), (*r.di));
    *b = 2 * dot((*r.di), (*sphere_to_ray));
    *c = dot((*sphere_to_ray), (*sphere_to_ray)) - 1;
    d = *b * *b - 4 * *a * *c;
    free(sphere_to_ray);
    return d;
}


void intersect_sphere(void *s, const t_ray transformed_ray, t_intersection **xs)
{
    t_sphere *sphere;
    double a;
    double b;
    double c;
    double d;

    if (!xs )
    {
        printf("Error: intersect_sphere: xs has no adress.\n");
        return;
    }
    sphere = (t_sphere *)s;
    d = calculate_discriminant(&a, &b, &c, transformed_ray, (*sphere->o));
    if (d > 0)
    {
        *xs = intersections(intersection((-b - sqrt(d)) / (2 * a), SPHERE, (void *)sphere), 
            intersection((-b + sqrt(d)) / (2 * a), SPHERE, (void *)sphere), NULL);
        if (!*xs)
            printf("Error: something went wrong with intersect_sphere.\n");
    }
}
