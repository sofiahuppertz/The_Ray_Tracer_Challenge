#include "light.h"

t_color *lighting(const t_material material, const t_point_light light, const t_tuple position, const t_tuple eyev, const t_tuple normalv, int in_shadow)
{
    t_color *color;
    t_color *effective_color;
    t_color *contributions[3];
    t_tuple *lightv;
    t_tuple *reflectv = NULL;
    double factors[3];

    if (material.pattern)
        color = stripe_at(material.pattern, position);
    else
        color = material.color;
        
    effective_color = shur_product(*color, *(light.intensity));
    lightv = norm(sub_tuple(*light.position, position));
    contributions[0] = scalar_color(*effective_color, material.ambient);
    if (in_shadow)
    {
        free_tuples(&lightv, NULL);
        free(effective_color);
        return contributions[0];
    }
    contributions[1] = black();
    contributions[2] = black();

    factors[0] = dot((const t_tuple)*lightv, normalv);
    if (factors[0] >= 0)
    {
        free(contributions[1]);
        contributions[1] = scalar_color(*effective_color, material.diffuse * factors[0]);
        neg_tuple(lightv);
        reflectv = reflection((const t_tuple)*lightv, normalv);
        factors[1] = dot((const t_tuple)*reflectv, eyev);
        if (factors[1] > 0)
        {
            free(contributions[2]);
            factors[2] = pow(factors[1], material.shininess) * material.specular;
            contributions[2] = scalar_color(*(light.intensity), factors[2]);
        }
    }
    free(effective_color);
    free_tuples(&lightv, &reflectv, NULL);
    return add_colors(contributions[0], contributions[1], contributions[2], NULL);
}
