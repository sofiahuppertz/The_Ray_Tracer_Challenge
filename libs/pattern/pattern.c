#include "pattern.h"

t_pattern *stripe_pattern(t_color *a, t_color *b)
{
    t_pattern *p = calloc(1, sizeof(t_pattern));
    if (!p)
    {
        printf("Error: stripe_pattern : calloc failed.\n");
        return NULL; 
    }
    p->a = a;
    p->b = b;
    return p;
}

t_pattern *patterncpy(const t_pattern pattern)
{
    t_pattern *p = calloc(1, sizeof(t_pattern));
    if (!p)
    {
        printf("Error: patterncpy : calloc failed.\n");
        return NULL; 
    }
    p->a = colorcpy(*pattern.a);
    p->b = colorcpy(*pattern.b);
    return p;
}

void free_pattern(t_pattern **p)
{
    if (!p || !*p)
        return;
    free((*p)->a);
    free((*p)->b);
    free(*p);
    *p = NULL;
}