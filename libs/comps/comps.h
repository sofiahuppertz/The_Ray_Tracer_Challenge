/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:26 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:18:28 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPS_H
#define COMPS_H

#include "../shape/shape.h"

typedef struct s_comps
{
    double t;
    t_elem object;
    t_shape *object_ptr;
    t_tuple *point;
    t_tuple *eyev;
    t_tuple *normalv;
    t_tuple *over_point;
    t_tuple *under_point;
    t_tuple *reflectv;
    double n1;
    double n2;
    int inside;
} t_comps;

t_comps *prep_comps(const t_intersection hit, const t_ray r, t_intersection *xs);

void compute_normal(t_comps *comps);
void compute_epsilon_boundaries(t_comps *comps);
void get_refractive_indices(const t_intersection hit, t_intersection *xs, t_comps *comps);

void print_comps(t_comps *comps);
void free_comps(t_comps **comps);

#endif