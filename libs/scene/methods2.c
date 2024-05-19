/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:49 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void make_sphere(t_tuple *center, double diameter, t_color *color, t_attributes *attributes, ...)
{
    t_scene *_scene;
    t_sphere *sp;
    double radius;
    va_list extras;

    _scene = scene();
    if (!_scene || !center || !color)
    {
        printf("Error: make_sphere: invalid arguments.\n");
        return;
    }
    sp = sphere();
    if (!sp)
        return;
    set_material(&sp->shape, materialcpy(*_scene->material));
    set_pattern(sp->shape.material, solid(color));
    radius = diameter / 2.0;
    transform(&sp->shape, chain_tfs(translation(center->x, center->y, center->z), scaling(radius, radius, radius), NULL));
    if (attributes)
    {
        va_start(extras, attributes);
        set_extras(&sp->shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&sp->shape);
    free(center);
}

void make_plane(t_tuple *point, t_tuple *normal, t_color *color, t_attributes *attributes, ...)
{
    t_scene *_scene;
    t_plane *pl;
    t_matrix *rotate;
    t_matrix *translate;
    va_list extras;

    _scene = scene();
    if (!_scene || !point || !normal || !color)
    {
        printf("Error: make_plane: invalid arguments.\n");
        return;
    }
    pl = plane();
    if (!pl)
        return;
    set_material(&pl->shape, materialcpy(*_scene->material));
    set_pattern(pl->shape.material, solid(color));
    rotate = find_rotation_matrix(*normal);
    translate = translation(point->x, point->y, point->z);
    transform(&pl->shape, chain_tfs(translate, rotate, NULL));
    if (attributes)
    {
        va_start(extras, attributes);
        set_extras(&pl->shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&pl->shape);
    free_tuples(&normal, &point, NULL);
}

void make_cylinder(t_tuple *center, t_tuple *axis, double diameter, double height, t_color *color, t_attributes *attributes, ...)
{
    t_scene *_scene;
    t_cylinder *cy;
    t_matrix *rotate;
    double radius;
    va_list extras;

    _scene = scene();
    if (!_scene || !center || !axis || !color)
    {
        printf("Error: make_cylinder: invalid arguments.\n");
        return;
    }
    cy = cylinder();
    if (!cy)
        return;
    set_material(&cy->c.shape, materialcpy(*_scene->material));
    rotate = find_rotation_matrix(*axis);
    set_bounds(&cy->c, -height / 2.0, height / 2.0);
    set_closed(&cy->c, 1);
    radius = diameter / 2.0;
    transform(&cy->c.shape, chain_tfs(translation(center->x, center->y, center->z), rotate, scaling(radius, 1, radius), NULL));
    set_pattern(cy->c.shape.material, solid(color));
    if (attributes)
    {
        va_start(extras, attributes);
        set_extras(&cy->c.shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&cy->c.shape);
    free_tuples(&axis, &center, NULL);
}

void make_cone(t_tuple *c, t_tuple *axis, double unit_d, double height, t_color *color, t_attributes *attributes, ...)
{
    t_scene *_scene;
    t_matrix *rotate;
    t_cone *co;
    double radius;
    va_list extras;

    _scene = scene();
    if (!_scene || !c || !axis || !color)
    {
        printf("Error: make_cone: invalid arguments.\n");
        return;
    }
    co = cone();
    if (!co)
        return;
    set_material(&co->c.shape, materialcpy(*_scene->material));
    set_bounds(&co->c, -height, 0);
    set_closed(&co->c, 1);
    rotate = find_rotation_matrix(*axis);
    radius = unit_d / 2.0;
    set_pattern(co->c.shape.material, solid(color));
    transform(&co->c.shape, chain_tfs(translation(c->x, c->y, c->z), rotate, scaling(radius, 1, radius), translation(0, height / 2.0, 0), NULL));
    if (attributes)
    {
        va_start(extras, attributes);
        set_extras(&co->c.shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&co->c);
    free_tuples(&c, &axis, NULL);
}
