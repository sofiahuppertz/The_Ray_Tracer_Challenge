/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:05:52 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:06:17 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	print_intersections(const t_intersection *i)
{
	t_intersection	*tmp;

	if (!i)
	{
		printf("Error: print_intersection: i is NULL\n");
		return ;
	}
	tmp = (t_intersection *)i;
	while (tmp)
	{
		printf("t: %f\nobject: %d\n", tmp->t, tmp->object);
		tmp = tmp->next;
	}
}

void	add_intersection(t_intersection **_xs, t_intersection *new)
{
	if (!new)
	{
		return ;
	}
	if (!*_xs)
		*_xs = new;
	else
		*_xs = merge_sorted(_xs, &new);
}

void	free_intersections(t_intersection **initial)
{
	t_intersection	*temp;
	t_intersection	*next;

	if (!initial || !(*initial))
		return ;
	temp = *initial;
	while (temp->next)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	temp = NULL;
}

t_tuple	*position_at(const double t, const t_ray r)
{
	t_tuple	*position;
	t_tuple	*temp;

	temp = tuplecpy((const t_tuple)(*r.di));
	scalar_tuple(temp, t);
	position = add_tuple((const t_tuple)(*r.o), (const t_tuple)(*temp));
	free(temp);
	return (position);
}
