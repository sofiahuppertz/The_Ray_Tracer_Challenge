/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:49 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:22:16 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

void	print_cone(void *s)
{
	t_cone	*cone;

	cone = (t_cone *)s;
	if (!cone)
		return ;
	printf("Cone\n");
	printf("Origin: ");
	print_tuple((const t_tuple *)(cone->c.o));
	printf("Max: %f\n", cone->c.max_y);
	printf("Min: %f\n", cone->c.min_y);
	printf("Closed: %d\n", cone->c.closed);
	printf("Transform:\n");
	print_matrix(cone->c.shape.tr);
	printf("Material:\n");
	print_material(*(cone->c.shape.material));
}

double	disc_cone(void *cyl, const t_ray ray, t_intersection **_xs, t_disc_vars *vars)
{
	double			c;
	double			disc;
	t_intersection	*cap_xs;

	cap_xs = NULL;
	vars->a = pow(ray.di->x, 2) - pow(ray.di->y, 2) + pow(ray.di->z, 2);
	vars->b = 2 * ray.o->x * ray.di->x - 2 * ray.o->y * ray.di->y + 2 * ray.o->z
		* ray.di->z;
	if (equal(vars->a, 0) && equal(vars->b, 0))
	{
		intersect_caps((t_cyl *)cyl, ray, _xs);
		return (-1);
	}
	c = pow(ray.o->x, 2) - pow(ray.o->y, 2) + pow(ray.o->z, 2);
	if (equal(vars->a, 0))
	{
		*_xs = xs((-c / (2 * vars->b)), CYLINDRICAL, cyl);
		intersect_caps((t_cyl *)cyl, ray, &cap_xs);
		add_intersection(_xs, cap_xs);
		return (-1);
	}
	disc = pow(vars->b, 2) - 4 * vars->a * c;
	return (disc);
}

int	cone_check_cap(const t_ray r, double t, double y)
{
	double	x;
	double	z;

	x = r.o->x + t * r.di->x;
	z = r.o->z + t * r.di->z;
	return ((pow(x, 2) + pow(z, 2)) <= y);
}
