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
    t_intersection *xs;
    t_matrix *inverse_transform;
    t_ray *transformed_ray;
    double a;
    double b;
    double c;
    double d;

    xs = NULL;
    inverse_transform = inverse((const t_matrix)(*s.transform));
    if (!inverse_transform)
        return NULL;
    transformed_ray = transform_ray(r, inverse((const t_matrix)(*s.transform)));
    if (!transformed_ray)
    {
        free_matrix(&inverse_transform);
        return NULL;
    }
    d = calculate_discriminant(&a, &b, &c, (const t_ray)*transformed_ray, (*s.o));
    free_ray(&transformed_ray);
    free_matrix(&inverse_transform);
    if (d > 0)
    {
        xs = intersections(intersection((-b - sqrt(d)) / (2 * a), SPHERE), intersection((-b + sqrt(d)) / (2 * a), SPHERE), NULL);
        if (!xs)
            printf("Error: something went wrong with i_ray_sphere.\n");
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
    i->next = NULL;
    return i;
}

static t_intersection *merge(t_intersection **first, t_intersection **next)
{
    t_intersection *temp;
    t_intersection *prev;
    t_intersection *last_next;

    temp = *first;
    prev = NULL;
    last_next = NULL;
    while (temp && (*next))
    {
        if ((*next)->t < temp->t)
        {
            if (prev != NULL)
                prev->next = (*next);
            else
                *first = *next;
            last_next = *next; 
            while (last_next->next)
                last_next = last_next->next;
            last_next->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!temp && (*next))
    {
        if (prev)
            prev->next = (*next);
        else   
            *first = *next;
    }
    return *first;
}

t_intersection *intersections(t_intersection *initial, ...)
{
    t_intersection *first;
    t_intersection *next;
    va_list args;

    va_start(args, initial);
    first = initial;
    if (first ==  NULL)
        printf("Error: first arg of intersections is NULL\n");
    else
    {
        while (1)
        {
            next = (t_intersection *)va_arg(args, t_intersection*);
            if (next == NULL)
                break;
            first = merge(&first, &next);
        }  
    }
    return first;
}

int count_intersections(t_intersection *xs)
{
    t_intersection *temp;
    int count;

    temp = xs;
    count = 0;
    if (temp)
    {
        while (temp)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}

t_intersection *hit(t_intersection **xs)
{
    t_intersection *hit;

    if (!xs || !(*xs))
        return NULL;
    hit = *xs;
    if (hit->t < 0)
    {
        while (hit) 
        {
            hit = hit->next;
            if (hit && hit->t >= 0)
                return hit;
        }
        return NULL;
    }
    else
        return hit;
}

void print_intersection(const t_intersection *i)
{
    if (!i)
    {
        printf("Error: print_intersection: i is NULL\n");
        return;
    }
    printf("t: %f\nobject: %d\n", i->t, i->object);
}

void free_intersections(t_intersection **initial)
{
    t_intersection *temp;
    t_intersection *next;

    if (!initial || !(*initial))
        return;
    temp = *initial;
    while (temp->next)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
    temp = NULL;
}

t_tuple *position_at(const double t, const t_ray r)
{
    t_tuple *position;
    t_tuple *temp;

    temp = tuplecpy((const t_tuple)(*r.di));
    scalar_tuple(temp, t);

    position = add_tuple((const t_tuple)(*r.o), (const t_tuple)(*temp));
    free(temp);
    return position;
}