#include "pattern.h"

t_pattern *test_pattern( void )
{
    t_pattern *pat;

    pat = (t_pattern *)calloc(1, sizeof(t_pattern));
    if (!pat)
    {
        printf("Error: stripe_pattern calloc failed.\n");
    }
    pattern(black() , black(), pat);
    pat->local_pattern = test_pattern_at;
    return pat;
}

t_color *test_pattern_at(void *pattern, const t_tuple point)
{
    (void)pattern;
    return color(point.x, point.y, point.z);
}