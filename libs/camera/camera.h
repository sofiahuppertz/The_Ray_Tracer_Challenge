/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:17:57 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "../canvas/canvas.h"
#include "../world/world.h"

typedef struct s_camera
{
    t_tf tf;
    double hsize;
    double vsize;
    double half_width;
    double half_height;
    double field_of_view;
    double pixel_size;
    t_matrix *vt;
} t_camera;

t_matrix *view_transformation(t_tuple *from, t_tuple *to, t_tuple *up);
t_camera *camera(double hsize, double vsize, double field_of_view);
void pixel_size(t_camera *c);

t_ray *ray_for_pixel(t_camera *c, double pixel_x, double pixel_y);
void transform_camera(void *c, t_matrix *vt);
t_canvas *render(t_camera *c, t_world *w);
void print_camera(const t_camera *c);
t_color *pixel_at(t_canvas *c, int x, int y);

void free_camera(t_camera **c);

#endif