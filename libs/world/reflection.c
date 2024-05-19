/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:29:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:29:57 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_color *reflected_color(const t_world w, const t_comps comps, int remaining)
{
    t_color *color;
    t_color *reflected_color;
    t_ray *reflected_ray;
    t_material *m_ptr;

    m_ptr = comps.object_ptr->material;
    if (!m_ptr->reflective || remaining <= 0)
        return black();
    reflected_ray = ray(tuplecpy(*comps.over_point), tuplecpy(*comps.reflectv));
    color = color_at(w, *reflected_ray, remaining - 1);
    reflected_color = scalar_color(*color, m_ptr->reflective);
    free_ray(&reflected_ray);
    free(color);
    return reflected_color;
}
