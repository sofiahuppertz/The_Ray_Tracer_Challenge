/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_elm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:58 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 11:09:58 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_cylinder_utils(t_parse *p, char **split, char *str)
{
	char	**split_tmp;
	int		i;

	i = -1;
	split_tmp = ft_split(split[2], ',');
	while (split_tmp[++i])
	{
		if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1
			|| check_point(split[3], "pos") == 1
			|| check_point(split[4], "pos") == 1)
		{
			free_split(split);
			free_split(split_tmp);
			return (1);
		}
	}
	make_cy_or_co(p, split, str);
	free_split(split_tmp);
	return (0);
}

int	parse_cylinder(t_parse *p, char *line, char *str)
{
	char	**split;

	split = ft_split(line, ' ');
	if (count_nb_elm(split, 6) == 2)
	{
		free_split(split);
		return (1);
	}
	else if (count_nb_elm(split, 4) == 1)
	{
		if (check_extra(split, p) == 1 || count_nb_elm(split, 6
				+ p->count) == 1)
			return (1);
	}
	if (check_xyz(p, split) == 1 || check_diameter(split[3], p) == 1
		|| check_diameter(split[4], p) == 1 || check_rgb(split[5], p) == 1
		|| vector_range(split, p) == 1)
	{
		free_split(split);
		return (1);
	}
	if (parse_cylinder_utils(p, split, str) == 1)
		return (1);
	free_split(split);
	return (0);
}

int	parse_cone(t_parse *p, char *line, char *str)
{
	if (parse_cylinder(p, line, str) == 1)
		return (1);
	return (0);
}

int	parse_plan_utils(t_parse *p, char **split)
{
	t_make_plane	pl;

	if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1
		|| vector_range(split, p) == 1)
	{
		free_split(split);
		return (1);
	}
	pl.point = point(p->x, p->y, p->z);
	pl.normal = vector(p->vr_1, p->vr_2, p->vr_3);
	pl.color = color(div_255(p->r), div_255(p->g), div_255(p->b));
	make_plane(pl, p->params[0], p->params[1], p->params[2], p->params[3],
		p->params[4], p->params[5]);
	return (0);
}

int	parse_sphere_utils(t_parse *p, char **split)
{
	t_make_sphere	sp;

	if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1
		|| check_diameter(split[2], p) == 1
		|| check_point(split[2], "pos") == 1)
	{
		free_split(split);
		return (1);
	}
	sp.center = point(p->x, p->y, p->z);
	sp.diameter = p->diam;
	sp.color = color(div_255(p->r), div_255(p->g), div_255(p->b));
	make_sphere(sp, p->params[0], p->params[1],
		p->params[2], p->params[3], p->params[4], p->params[5]);
	return (0);
}
