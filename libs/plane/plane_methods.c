/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:18 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void plane_normal_at(void *p, const t_tuple object_point, t_tuple **normal)
{
    (void)p;
    (void)object_point;
    if (!normal)
        return;
    *normal = vector(0, 1, 0);
}

void intersect_plane(void *p, const t_ray transformed_ray, t_intersection **xs_list)
{
    t_plane *plane;
    double t;

    plane = (t_plane *)p;

    if (fabs(transformed_ray.di->y) < EPSILON)
    {
        *xs_list = NULL;
        return;
    }
    t = -transformed_ray.o->y / transformed_ray.di->y;
    *xs_list = xs(t, PLANE, (void *)plane);
}

void print_plane(void *p)
{
    t_plane *_plane;

    _plane = (t_plane *)p;

    printf("Plane: ");
    print_material(*_plane->shape.material);
    printf("Transform:\n");
    print_matrix((void *)_plane->shape.tr);
}