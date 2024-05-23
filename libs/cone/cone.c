/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:52 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:44:30 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

t_cone	*cone(void)
{
	t_cone	*cone;

	cone = (t_cone *)calloc(1, sizeof(t_cone));
	if (!cone)
	{
		printf("Error: cone: calloc failed.\n");
		return (NULL);
	}
	cyl(&cone->c);
	cone->c.shape.local_free = free_cone;
	cone->c.shape.local_print = print_cone;
	cone->c.local_calc_disc = disc_cone;
	cone->c.local_check_cap = cone_check_cap;
	cone->c.local_cyl_normal = cone_normal;
	return (cone);
}

void	free_cone(void *s)
{
	t_cone	*cone;

	cone = (t_cone *)s;
	if (!cone)
		return ;
	free(cone->c.o);
	free(cone);
}

void	cone_normal(t_tuple object_point, t_tuple **normal)
{
	double y;

	y = sqrt(pow(object_point.x, 2) + pow(object_point.z, 2));
	if (object_point.y > 0)
		y = -y;
	*normal = vector(object_point.x, y, object_point.z);
}