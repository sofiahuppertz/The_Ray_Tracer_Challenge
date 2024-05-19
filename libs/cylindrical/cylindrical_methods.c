/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:19:17 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylindrical.h"

static t_intersection *find_solutions(t_cyl *cyl, const t_ray ray, double disc, double a, double b)
{
    t_intersection *_xs;
    t_intersection *cap_xs;
    double t0;
    double t1;

    _xs = NULL;
    cap_xs = NULL;
    t0 = (-b - sqrt(disc)) / (2 * a);
    t1 = (-b + sqrt(disc)) / (2 * a);
    if (t0 > t1)
    {
        double tmp = t0;
        t0 = t1;
        t1 = tmp;
    }
    double y0 = ray.o->y + (t0 * ray.di->y);
    if (cyl->min_y < y0 && y0 < cyl->max_y)
        _xs = xs(t0, CYLINDRICAL, (void *)cyl);

    double y1 = ray.o->y + (t1 * ray.di->y);
    if (cyl->min_y < y1 && y1 < cyl->max_y)
        add_intersection(&_xs, xs(t1, CYLINDRICAL, (void *)cyl));
    intersect_caps(cyl, ray, &cap_xs);
    add_intersection(&_xs, cap_xs);
    return _xs;
}

void intersect_cyl(void *s, const t_ray transformed_ray, t_intersection **_xs)
{
    t_cyl *cyl;
    double disc;
    double a;
    double b;

    a = 0;
    b = 0;
    cyl = (t_cyl *)s;
    *_xs = NULL;
    disc = cyl->local_calc_disc(cyl, transformed_ray, _xs, &a, &b);
    if (disc < 0)
        return;
    *_xs = find_solutions(cyl, transformed_ray, disc, a, b);
}

void intersect_caps(t_cyl *cyl, const t_ray r, t_intersection **_xs)
{
    double t;
    t_intersection *i1 = NULL;
    t_intersection *i2 = NULL;

    if (!cyl->closed || equal(r.di->y, 0))
        return;

    t = (cyl->min_y - r.o->y) / r.di->y;
    if (cyl->local_check_cap(r, t, fabs(cyl->min_y)))
        i1 = xs(t, CYLINDRICAL, cyl);

    t = (cyl->max_y - r.o->y) / r.di->y;
    if (cyl->local_check_cap(r, t, fabs(cyl->max_y)))
        i2 = xs(t, CYLINDRICAL, cyl);
    *_xs = merge_sorted(&i1, &i2);
}

void cyl_normal_at(void *s, const t_tuple object_point, t_tuple **normal)
{
    t_cyl *cyl;
    double dist;

    cyl = (t_cyl *)s;
    if (!cyl)
        return;

    dist = pow(object_point.x, 2) + pow(object_point.z, 2);

    if (dist < 1 && object_point.y >= cyl->max_y - EPSILON)
    {
        *normal = vector(0, 1, 0);
    }
    else if (dist < 1 && object_point.y <= cyl->min_y + EPSILON)
    {
        *normal = vector(0, -1, 0);
    }
    else
    {
        cyl->local_cyl_normal(object_point, normal);
    }
    if (!*normal)
    {
        printf("Error: cylinder_normal_at: operation failed.\n");
        *normal = NULL;
    }
}