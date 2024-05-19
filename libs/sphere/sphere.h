/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:29 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:24:30 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
#define SPHERE_H

#include "../shape/shape.h"

#include "stdlib.h"

typedef struct s_sphere
{
    t_shape shape;
    t_tuple *o;
    double radius;
} t_sphere;

// Constructors destructors
t_sphere *sphere(void);
t_sphere *glass_sphere(void);
void free_sphere(void *s);
void print_sphere(void *s);

// Methods
void sphere_normal_at(void *s, const t_tuple object_point, t_tuple **normal);
void intersect_sphere(void *s, const t_ray transformed_ray, t_intersection **xs);

#endif