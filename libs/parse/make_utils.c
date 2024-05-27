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
	if (ft_strncmp(str, "cy", 2) == 0)
	{
		make_cylinder(point(p->x, p->y, p->z), vector(p->vr_1,
				p->vr_2, p->vr_3), ft_atof(split[3]), ft_atof(split[4]),
			color(div_255(p->r), div_255(p->g), div_255(p->b)),
			p->params[0], p->params[1], p->params[2], p->params[3],
			p->params[4], p->params[5]);
	}
	else if (ft_strncmp(str, "co", 2) == 0)
	{
		make_cone(point(p->x, p->y, p->z), vector(p->vr_1, p->vr_2, p->vr_3),
			ft_atof(split[3]), ft_atof(split[4]), color(div_255(p->r),
				div_255(p->g), div_255(p->b)), p->params[0], p->params[1],
			p->params[2], p->params[3], p->params[4], p->params[5]);
	}
}
