#include "intersection.h"


t_intersection *intersection(const double t, const t_elem object, void *object_ptr)
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
    i->object_ptr = object_ptr;
    i->next = NULL;
    return i;
}

t_intersection *merge_sorted(t_intersection **first, t_intersection **next)
{

    if (*first == NULL) return *next;
    if (*next == NULL) return *first;

    t_intersection *result = NULL;

    if ((*first)->t <= (*next)->t) 
    {
        result = *first;
        result->next = merge_sorted(&((*first)->next), next);
    } 
    else 
    {
        result = *next;
        result->next = merge_sorted(first, &((*next)->next));
    }
    return result;
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
            first = merge_sorted(&first, &next);
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

void print_intersections(const t_intersection *i)
{
    t_intersection *tmp;

    if (!i)
    {
        //printf("Error: print_intersection: i is NULL\n");
        return;
    }
    tmp = (t_intersection *)i;
    while (tmp)
    {
        printf("t: %f\nobject: %d\n", tmp->t, tmp->object);
        tmp = tmp->next;
    }
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