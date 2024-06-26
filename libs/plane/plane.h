/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:25 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:51 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "../shape/shape.h"

typedef struct s_plane
{
	t_shape	shape;

}			t_plane;

t_plane		*plane(void);
t_matrix	*find_rotation_matrix(const t_tuple normal);
void		plane_normal_at(void *p, const t_tuple object_point,
				t_tuple **normal);
void		intersect_plane(void *p, const t_ray transformed_ray,
				t_intersection **xs);
void		print_plane(void *s);
void		free_plane(void *p);

#endif
