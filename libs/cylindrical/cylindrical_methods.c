/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 15:00:37 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylindrical.h"

static void swap_if_needed(double *t0, double *t1) {
	if (*t0 > *t1) {
		double tmp = *t0;
		*t0 = *t1;
		*t1 = tmp;
	}
}

static t_intersection *find_solutions(t_cyl *cyl, const t_ray ray, double disc, t_disc_vars *vars) 
{
	t_intersection *_xs;
	t_intersection *cap_xs;
	t_inter_info i;

	_xs = NULL;
	cap_xs = NULL;
	i.t0 = (-vars->b - sqrt(disc)) / (2 * vars->a);
	i.t1 = (-vars->b + sqrt(disc)) / (2 * vars->a);
	swap_if_needed(&i.t0, &i.t1);

	i.y0 = ray.o->y + (i.t0 * ray.di->y);
	if (cyl->min_y < i.y0 && i.y0 < cyl->max_y)
		_xs = xs(i.t0, CYLINDRICAL, (void *)cyl);

	i.y1 = ray.o->y + (i.t1 * ray.di->y);
	if (cyl->min_y < i.y1 && i.y1 < cyl->max_y)
		add_intersection(&_xs, xs(i.t1, CYLINDRICAL, (void *)cyl));
	intersect_caps(cyl, ray, &cap_xs);
	add_intersection(&_xs, cap_xs);

	return (_xs);
}

void	intersect_cyl(void *s, const t_ray transformed_ray,
		t_intersection **_xs)
{
	t_cyl	*cyl;
	double	disc;
	t_disc_vars	vars;

	vars.a = 0;
	vars.b = 0;
	cyl = (t_cyl *)s;
	*_xs = NULL;
	disc = cyl->local_calc_disc(cyl, transformed_ray, _xs, &vars);
	if (disc < 0)
		return ;
	*_xs = find_solutions(cyl, transformed_ray, disc, &vars);
}

void	intersect_caps(t_cyl *cyl, const t_ray r, t_intersection **_xs)
{
	double			t;
	t_intersection	*i1;
	t_intersection	*i2;

	i1 = NULL;
	i2 = NULL;
	if (!cyl->closed || equal(r.di->y, 0))
		return ;
	t = (cyl->min_y - r.o->y) / r.di->y;
	if (cyl->local_check_cap(r, t, fabs(cyl->min_y)))
		i1 = xs(t, CYLINDRICAL, cyl);
	t = (cyl->max_y - r.o->y) / r.di->y;
	if (cyl->local_check_cap(r, t, fabs(cyl->max_y)))
		i2 = xs(t, CYLINDRICAL, cyl);
	*_xs = merge_sorted(&i1, &i2);
}

void	cyl_normal_at(void *s, const t_tuple object_point, t_tuple **normal)
{
	t_cyl	*cyl;
	double	dist;

	cyl = (t_cyl *)s;
	if (!cyl)
		return ;
	dist = pow(object_point.x, 2) + pow(object_point.z, 2);
	if (dist < 1 && object_point.y >= cyl->max_y - EPSILON)
	{
		*normal = vector(0, 1, 0);
	}
	else if (dist < 1 && object_point.y <= cyl->min_y + EPSILON)
	{
		*normal = vector(0, -1, 0);
	}
	else
	{
		cyl->local_cyl_normal(object_point, normal);
	}
	if (!*normal)
	{
		printf("Error: cylinder_normal_at: operation failed.\n");
		*normal = NULL;
	}
}
