/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:58 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 11:09:58 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	make_cy_or_co(t_parse *p, char **split, char *str)
{
	t_make_cylindrical c;

	c.center = point(p->x, p->y, p->z);
	c.axis = vector(p->vr_1, p->vr_2, p->vr_3);
	c.diameter = ft_atof(split[3]);
	c.height = ft_atof(split[4]);
	c.color = color(div_255(p->r), div_255(p->g), div_255(p->b));
	if (ft_strncmp(str, "cy", 2) == 0)
	{
		make_cylinder(c, p->params[0], p->params[1], p->params[2], 
		p->params[3], p->params[4], p->params[5]);
	}
	else if (ft_strncmp(str, "co", 2) == 0)
	{
		make_cone(c, p->params[0], p->params[1], p->params[2],
		p->params[3], p->params[4], p->params[5]);
	}
}
