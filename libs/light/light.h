/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:46:23 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../shape/shape.h"

typedef struct s_point_light
{
	t_color		*intensity;
	t_tuple		*position;
}				t_point_light;

t_color			*lighting(const t_material material, const t_shape object,
					const t_point_light light, const t_tuple position,
					const t_tuple eyev, const t_tuple normalv, int in_shadow);

t_point_light	*point_light(t_color *intensity, t_tuple *position);
void			free_point_light(t_point_light **light);
void			print_point_light(const t_point_light light);

#endif