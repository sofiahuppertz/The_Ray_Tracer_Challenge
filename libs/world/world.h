/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:14 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:27 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../comps/comps.h"
# include "../cone/cone.h"
# include "../cylinder/cylinder.h"
# include "../light/light.h"
# include "../plane/plane.h"
# include "../sphere/sphere.h"

typedef struct s_world
{
	t_point_light	*light;
	t_shape			*shapes;
}					t_world;

// Constructors
t_world				*default_world(void);
t_world				*empty_world(void);

// Setters -ish
void				set_shape(t_world *w, t_shape *new_shape);
void				set_light(t_world *w, t_point_light *l);

// Other functions
t_intersection		*intersect_world(const t_world w, const t_ray r);
t_color				*color_at(const t_world w, const t_ray r, int remaining);
t_color				*shade_hit(const t_world w, const t_comps comps,
						int remaining);
t_color				*reflected_color(const t_world w, const t_comps comps,
						int remaining);
t_color				*refracted_color(const t_world w, const t_comps comps,
						int remaining);
double				schlick(const t_comps comps);
int					is_shadowed(const t_world w, const t_tuple point);
t_color				*rfl_tsy_pos(const t_world w, const t_comps comps,
						int remaining, t_color *surface);

// Free functions
void				free_world(t_world **w);

t_sphere			*set(t_sphere *s1, t_sphere *s2, t_material *m, t_world *w);

#endif