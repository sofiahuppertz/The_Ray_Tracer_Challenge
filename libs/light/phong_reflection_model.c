/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:01 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:20:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_color *lighting(const t_material material, const t_shape object, const t_point_light light, const t_tuple position, const t_tuple eyev, const t_tuple normalv, int in_shadow)
{
    t_color *temp;
    t_color *effective_color;
    t_color *ambient;
    t_color *diffuse;
    t_color *specular;
    t_tuple *lightv;
    t_tuple *reflectv = NULL;
    double lDotN;
    double eDotR;

    temp = pattern_at_object(material.pattern, object, position);

    effective_color = shur_product(*temp, *(light.intensity));

    free(temp);
    temp = shur_product(*material.ambient_color, *effective_color);
    free(effective_color);
    effective_color = temp;

    lightv = norm(sub_tuple(*light.position, position));
    ambient = scalar_color(*effective_color, material.ambient);
    if (in_shadow)
    {
        free_tuples(&lightv, NULL);
        free(effective_color);
        return ambient;
    }

    diffuse = black();
    specular = black();

    lDotN = dot(*lightv, normalv);
    if (lDotN >= 0)
    {
        free(diffuse);
        diffuse = scalar_color(*effective_color, material.diffuse * lDotN);
        neg_tuple(lightv);
        reflectv = reflection(*lightv, normalv);
        eDotR = dot(*reflectv, eyev);
        if (eDotR > 0)
        {
            free(specular);
            double factor = pow(eDotR, material.shininess) * material.specular;
            specular = scalar_color(*(light.intensity), factor);
        }
    }
    free(effective_color);
    free_tuples(&lightv, &reflectv, NULL);

    t_color *final = add_colors(ambient, specular, diffuse, NULL);
    return final;
}
