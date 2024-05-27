/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:21:09 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "../cylindrical/cylindrical.h"

typedef struct s_cylinder
{
	t_cyl	c;
	double	radius;

}			t_cylinder;

t_cylinder	*cylinder(void);
void		free_cylinder(void *s);

void		print_cylinder(void *s);
double		disc_cylinder(void *cyl, const t_ray ray, t_intersection **_xs,
				t_disc_vars *vars);
int			cylinder_check_cap(const t_ray r, double t, double y);
void		cylinder_normal(const t_tuple object_point, t_tuple **normal);

#endif