#include "pattern.h"

t_pattern *stripe(t_color *a, t_color *b)
{
    t_pattern *stripe;

    stripe = (t_pattern *)calloc(1, sizeof(t_pattern));
    if (!stripe)
    {
        printf("Error: stripe_pattern calloc failed.\n");
    }
    pattern(a , b, stripe);
    stripe->local_pattern = stripe_at;
    return stripe;
}

t_color *stripe_at(void *pattern, const t_tuple point)
{
    t_pattern *stripe;
    
    stripe = (t_pattern *)pattern;
    if ((int)floor(point.x) % 2 == 0)
        return colorcpy(*stripe->a);
    return colorcpy(*stripe->b);
}
