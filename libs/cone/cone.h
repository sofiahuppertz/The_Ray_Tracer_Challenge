/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:56 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:22:23 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "../cylindrical/cylindrical.h"

typedef struct s_cone
{
	t_cyl	c;
}			t_cone;

t_cone		*cone(void);
void		free_cone(void *s);

void		print_cone(void *s);
double		disc_cone(void *cyl, const t_ray ray, t_intersection **_xs,
				t_disc_vars *vars);
int			cone_check_cap(const t_ray r, double t, double y);
void		cone_normal(const t_tuple object_point, t_tuple **normal);

#endif