#include "world.h"

double schlick(const t_comps comps)
{
    double cos;
    double n;
    double sin2_t;
    double cos_t;
    double r0;

    cos = dot(*comps.eyev, *comps.normalv);
    if (comps.n1 >comps.n2)
    {
        n = comps.n1 / comps.n2;
        sin2_t = n * n * (1.0 - cos * cos);
        if (sin2_t > 1.0)
            return 1.0;
        cos_t = sqrt(1.0 - sin2_t);
        cos = cos_t;
    }
    r0 = pow((comps.n1 - comps.n2) / (comps.n1 + comps.n2), 2);
    return r0 + (1 - r0) * pow((1 - cos), 5);
}