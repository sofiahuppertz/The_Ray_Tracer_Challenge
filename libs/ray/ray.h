/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:35 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:50:49 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../matrix/matrix.h"
# include "../tuple/tuple.h"

typedef struct s_ray
{
	t_tf	tf;
	t_tuple	*o;
	t_tuple	*di;
}			t_ray;

t_ray		*ray(t_tuple *origin, t_tuple *direction);
void		transform_ray(void *ray, t_matrix *transformation);
t_ray		*raycpy(const t_ray r);

void		print_ray(const t_ray *r);
void		free_ray(t_ray **r);

t_tuple		*position(t_ray r, double t);

#endif