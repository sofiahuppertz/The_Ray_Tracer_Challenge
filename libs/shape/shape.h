/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:53:37 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "../intersection/intersection.h"
# include "../material/material.h"
# include "../matrix/matrix.h"

typedef void			(*t_local_intersect)(void *shape, t_ray ray,
				t_intersection **xs_ptr);
typedef void			(*t_local_normal_at)(void *shape, t_tuple object_point,
				t_tuple **normal_ptr);
typedef void			(*t_local_free)(void *shape);
typedef void			(*t_local_print)(void *shape);

typedef struct s_shape
{
	t_tf				tf;
	int					id;
	t_matrix			*tr;
	t_material			*material;
	t_local_intersect	local_intersect;
	t_local_normal_at	local_normal_at;
	t_local_free		local_free;
	t_local_print		local_print;
	struct s_shape		*next;
	struct s_shape		*container_next;
	int					can_cast_shadow;
}						t_shape;

// Constructors
void					shape(t_elem type, t_shape *shape);

// Setters
void					set_transform(void *s, t_matrix *transformation);
void					set_material(t_shape *shape, t_material *material);

// Methods
t_intersection			*intersect(const t_shape *shape, const t_ray ray,
							t_elem type);
t_intersection			*intersect_shapes(t_shape *shapes, const t_ray ray);
t_tuple					*normal_at(t_shape *shape, const t_tuple world_point);
void					print_shapes(t_shape *shapes);
t_color					*pattern_at_object(const t_pattern *pattern,
							const t_shape object, const t_tuple point);

// Destructors
void					free_shape(t_shape *s);

#endif