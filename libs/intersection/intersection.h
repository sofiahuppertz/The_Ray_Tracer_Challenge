/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:43 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:45:58 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "../ray/ray.h"
# include <stdarg.h>

typedef struct s_intersection
{
	double					t;
	t_elem					object;
	void					*object_ptr;
	struct s_intersection	*next;
}							t_intersection;

t_intersection				*xs(const double t, const t_elem object,
								void *object_ptr);
t_intersection				*merge_sorted(t_intersection **first,
								t_intersection **next);
t_intersection				*intersections(t_intersection *initial, ...);
void						add_intersection(t_intersection **_xs,
								t_intersection *new);

t_intersection				*hit(t_intersection **xs);
int							count_intersections(t_intersection *xs);
void						print_intersections(const t_intersection *i);

t_tuple						*position_at(const double t, const t_ray r);

void						free_intersections(t_intersection **initial);

#endif
