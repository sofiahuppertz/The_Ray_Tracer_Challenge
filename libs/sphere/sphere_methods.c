/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:22 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 11:18:29 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void	sphere_normal_at(void *s, const t_tuple object_point, t_tuple **normal)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)s;
	*normal = sub_tuple(object_point, *sphere->o);
	if (!*normal)
	{
		printf("Error: sphere_normal_at: operation failed.\n");
		*normal = NULL;
	}
}

static double	*get_vars( void )
{
	static double	vars[3];

	return (vars);
}

static double	calculate_discriminant(const t_ray r, const t_tuple s_o)
{
	t_tuple	*sphere_to_ray;
	double	*vars;
	double	d;

	sphere_to_ray = sub_tuple((*r.o), s_o);
	vars = get_vars();
	vars[0] = dot((*r.di), (*r.di));
	vars[1] = 2 * dot((*r.di), (*sphere_to_ray));
	vars[2] = dot((*sphere_to_ray), (*sphere_to_ray)) - 1;
	d = vars[1] * vars[1] - 4 * vars[0] * vars[2];
	free(sphere_to_ray);
	return (d);
}

void	intersect_sphere(void *s, const t_ray transformed_ray,
		t_intersection **xs_list)
{
	t_sphere	*sphere;
	double		*vars;
	double		d;

	if (!xs_list)
	{
		printf("Error: intersect_sphere: xs_list has no adress.\n");
		return ;
	}
	sphere = (t_sphere *)s;
	d = calculate_discriminant(transformed_ray, (*sphere->o));
	vars = get_vars();
	if (d > 0)
	{
		*xs_list = intersections(xs((-vars[1] - sqrt(d))
					/ (2 * vars[0]), SPHERE, (void *)sphere),
				xs((-vars[1] + sqrt(d)) / (2 * vars[0]), SPHERE,
					(void *)sphere), NULL);
		if (!*xs_list)
			printf("Error: something went wrong with intersect_sphere.\n");
	}
}
