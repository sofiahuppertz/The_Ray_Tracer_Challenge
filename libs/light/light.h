/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 15:24:54 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../comps/comps.h"

typedef struct s_light_calculation
{
	t_color	*temp;
	t_color	*effective_color;
	t_color	*ambient;
	t_color	*diffuse;
	t_color	*specular;
	t_color	*final;
	t_tuple *lightv;
	double lDotN;
}				t_light_calculation;

typedef struct s_point_light
{
	t_color		*intensity;
	t_tuple		*position;
}				t_point_light;

t_color			*lighting(const t_material material, t_comps comps, 
					const t_point_light light, int in_shadow);

t_point_light	*point_light(t_color *intensity, t_tuple *position);
void			free_point_light(t_point_light **light);
void			print_point_light(const t_point_light light);

#endif