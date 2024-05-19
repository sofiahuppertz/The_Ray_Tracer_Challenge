/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:41:41 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

#include "../camera/camera.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define HEIGHT 1000
#define WIDTH 1000

typedef struct s_scene
{
    t_material *material;
    t_camera *camera;
    t_world *world;
    t_canvas *canvas;

} t_scene;

typedef struct s_attributes
{
    char *key;
    void *value;
} t_attributes;

t_scene *scene(void);

void make_ambient_light(double ratio, t_color *color);
void make_camera(t_tuple *view_point, t_tuple *orientation, double field_of_view);
void make_light(t_tuple *position, double brightness, t_color *color);

void make_sphere(t_tuple *center, double diameter, t_color *color, t_attributes *attributes, ...);
void make_plane(t_tuple *point, t_tuple *normal, t_color *color, t_attributes *attributes, ...);
void make_cylinder(t_tuple *center, t_tuple *axis, double diameter, double height, t_color *color, t_attributes *attributes, ...);
void make_cone(t_tuple *center, t_tuple *axis, double unit_d, double height, t_color *color, t_attributes *attributes, ...);
void set_extras(t_shape *shape, t_attributes *first_extra, va_list extras);

t_attributes *checker(t_color *a, t_color *b);
t_attributes *stripe(t_color *a, t_color *b, double width, double rotation_z);
t_attributes *rfl(double reflectivity);
t_attributes *rfr(double refractive_index);
t_attributes *tsy(double transparency);

int close_window(void *param);
int key_press(int keycode, void *param);
int set_events_and_display(t_canvas *canvas);

#endif