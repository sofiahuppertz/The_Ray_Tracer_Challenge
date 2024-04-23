#include "pattern.h"

t_color *stripe_at(const t_pattern *pattern, const t_tuple point)
{
    if ((int)floor(point.x) % 2 == 0)
        return pattern->a;
    return pattern->b;
}

