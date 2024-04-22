#include "sphere.h"

t_tuple *normal_at(const t_sphere s, const t_tuple world_point)
{
    t_tuple *object_point;
    t_tuple *normal;
    t_matrix *t;

    object_point = tuplecpy(world_point);
    transform( object_point, inverse(*s.shape.tr));
    normal = sub_tuple((const t_tuple)(*object_point), (const t_tuple)(*s.o));
    free(object_point);
    if (!normal)
    {
        printf("Error: normal_at: operation failed.\n");
        return NULL;
    }
    t = inverse(*s.shape.tr);
    transpose(&t);
    transform_tuple(normal, t);
    normal->w = 0;
    norm(normal);
    return normal;
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
