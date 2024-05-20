/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:44 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/20 15:14:25 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void make_camera(t_tuple *view_point, t_tuple *orientation, double field_of_view)
{
    t_scene *_scene;
    t_camera *cam;
    t_matrix *vt;

    _scene = scene();
    if (!_scene || !view_point || !orientation)
    {
        printf("Error: make_camera: invalid arguments.\n");
        return;
    }
    cam = camera(WIDTH, HEIGHT, field_of_view);
    if (!cam)
        return;
    vt = view_transformation(view_point, orientation, vector(0, 1, 0));
    if (!vt)
    {
        free_camera(&cam);
        return;
    }
    transform(cam, vt);
    if (_scene->camera)
    {
        free_camera(&_scene->camera);
    }
    _scene->camera = cam;
}

void make_ambient_light(double ratio, t_color *color)
{
    t_scene *_scene;

    _scene = scene();
    if (!_scene || !color)
    {
        printf("Error: make_ambient_light: invalid arguments.\n");
        return;
    }
    if (!_scene->material)
    {
        _scene->material = default_material();
    }
    if (!_scene->material)
    {
        return;
    }
    set_ambient(_scene->material, ratio);
    set_ambient_color(_scene->material, color);
}

void make_light(t_tuple *position, double brightness, t_color *color)
{
    t_point_light *light;
    t_scene *_scene;

    _scene = scene();
    if (!_scene || !position || !color)
    {
        printf("Error: make_light: invalid arguments.\n");
        return;
    }
    light = point_light(color, position);
    if (!light)
        return;
    if (_scene->world->light)
    {
        free_point_light(&_scene->world->light);
    }
    _scene->world->light = light;
    if (!_scene->material)
    {
        _scene->material = default_material();
    }
    set_diffuse(_scene->material, brightness);
}
