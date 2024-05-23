/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_methods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:03 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:44:51 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	print_cylinder(void *s)
{
	const t_cylinder	*cylinder;

	cylinder = (t_cylinder *)s;
	if (!cylinder)
		return ;
	printf("Cylinder %d\n", cylinder->c.shape.id);
	printf("Origin: ");
	print_tuple((const t_tuple *)(cylinder->c.o));
	printf("Radius: %f\n", cylinder->radius);
	printf("Transform:\n");
	print_matrix(cylinder->c.shape.tr);
	printf("Material:\n");
	print_material(*(cylinder->c.shape.material));
}

double	disc_cylinder(void *cyl, const t_ray ray, t_intersection **_xs,
		double *a, double *b)
{
	double	c;
	double	disc;

	*a = pow(ray.di->x, 2) + pow(ray.di->z, 2);
	if (equal(*a, 0))
	{
		intersect_caps((t_cyl *)cyl, ray, _xs);
		return (-1);
	}
	*b = 2 * ray.o->x * ray.di->x + (2 * ray.o->z * ray.di->z);
	c = pow(ray.o->x, 2) + pow(ray.o->z, 2) - 1;
	disc = pow(*b, 2) - 4 * *a * c;
	return (disc);
}

int	cylinder_check_cap(const t_ray r, double t, double y)
{
	double	x;
	double	z;

	(void)y;
	x = r.o->x + t * r.di->x;
	z = r.o->z + t * r.di->z;
	return ((pow(x, 2) + pow(z, 2)) <= 1);
}

void	cylinder_normal(t_tuple object_point, t_tuple **normal)
{
	*normal = vector(object_point.x, 0, object_point.z);
}
