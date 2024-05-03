#include "pattern.h"

t_pattern *checker_pattern(t_color *a, t_color *b)
{
    t_pattern *checker;

    checker = (t_pattern *)calloc(1, sizeof(t_pattern));
    if (!checker)
    {
        printf("Error: checker calloc failed.\n");
    }
    pattern(a , b, checker);
    checker->local_pattern = checker_at;
    return checker;
}

t_color *checker_at(void *pattern, const t_tuple point)
{
    t_pattern *checker;
    int variable;

    checker = (t_pattern *)pattern;
    variable = (int)floor(point.x) + (int)floor(point.y) + (int)floor(point.z);
    if (variable % 2 == 0)
        return colorcpy(*checker->a);
    return colorcpy(*checker->b);
}