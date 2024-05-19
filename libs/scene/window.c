/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:00 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:24:01 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int set_events_and_display(t_canvas *canvas)
{
    mlx_key_hook(canvas->mlx_win, key_press, NULL);
    mlx_hook(canvas->mlx_win, 17, 0L, close_window, NULL);
    mlx_put_image_to_window(canvas->mlx, canvas->mlx_win, canvas->img.img, 0, 0);
    mlx_loop(canvas->mlx);
    return 0;
}

int close_window(void *param)
{
    t_scene *_scene;

    _scene = scene();
    if (!_scene)
        return (1);
    (void)param;
    if (_scene->world)
    {
        free_world(&_scene->world);
    }
    if (_scene->camera)
    {
        free_camera(&_scene->camera);
    }
    if (_scene->material)
    {
        free_material(&_scene->material);
    }
    if (_scene->canvas)
    {
        free_canvas(_scene->canvas);
    }
    free(_scene);
    exit(0);
}

int key_press(int keycode, void *param)
{
    if (keycode == 65307)
        close_window(NULL);
    (void)param;
    return (0);
}
