#include "intersection.h"

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


t_intersection *i_ray_sphere(const t_sphere *s, const t_ray r)
{
    t_intersection *xs;
    t_matrix *inverse_transform;
    t_ray *transformed_ray;
    double a;
    double b;
    double c;
    double d;

    xs = NULL;
    inverse_transform = inverse(*s->transform);
    if (!inverse_transform)
        return NULL;
    transformed_ray = transform_ray(r, inverse(*s->transform));
    if (!transformed_ray)
    {
        free_matrix(&inverse_transform);
        return NULL;
    }
    d = calculate_discriminant(&a, &b, &c, *transformed_ray, (*s->o));
    free_ray(&transformed_ray);
    free_matrix(&inverse_transform);
    if (d > 0)
    {
        xs = intersections(intersection((-b - sqrt(d)) / (2 * a), SPHERE, (void *)s), 
            intersection((-b + sqrt(d)) / (2 * a), SPHERE, (void *)s), NULL);
        if (!xs)
            printf("Error: something went wrong with i_ray_sphere.\n");
    }
    return xs;
}


t_intersection *multiple_i_ray_sphere(const t_sphere *s, const t_ray r)
{
    t_intersection *xs;
    t_intersection *tmp;
    t_sphere *ptr;

    ptr = (t_sphere *)s;
    xs = NULL;
    tmp = NULL;
    while (ptr)
    {
        tmp = i_ray_sphere(ptr, r);
        xs = merge_sorted(&xs, &tmp);
        ptr = ptr->next;
    }
    return xs;
}