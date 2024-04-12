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


t_intersection *i_ray_sphere(const t_sphere s, const t_ray r)
{
    t_intersection **xs;
    t_intersection *ptr;
    double a;
    double b;
    double c;
    double d;

    xs = NULL;
    d = calculate_discriminant(&a, &b, &c, r, (*s.o));
    if (d < 0)
        printf("Intersection ray-sphere: no solutions\n");
    else
    {
        xs = (t_intersection **)calloc(2, sizeof(t_intersection));
        if (!xs)
            printf("Error: could not allocate memory for intersections\n");
        else
        {
            xs[0] = intersection((-b - sqrt(d)) / (2 * a), SPHERE);
            xs[1] = intersection((-b + sqrt(d)) / (2 * a), SPHERE);
        }
    }
    return xs;
}


t_intersection *intersection(const double t, const t_object object)
{
    t_intersection *i;

    i = (t_intersection *)calloc(1, sizeof(t_intersection));
    if (!i)
    {
        printf("Error: could not allocate memory for intersection\n");
        return NULL;
    }
    i->t = t;
    i->object = object;
    return i;
}

int count_solutions(t_intersection **xs)
{
    int count;

    count = 0;
    if (xs)
    {
        while (xs[count])
            count++;
    }
    return count;
}
