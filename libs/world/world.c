/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:19 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	*empty_world(void)
{
	t_world	*w;

	w = (t_world *)calloc(sizeof(t_world), 1);
	if (!w)
		return (NULL);
	return (w);
}

t_world	*default_world(void)
{
	t_world		*w;
	t_material	*m;
	t_sphere	*s1;
	t_sphere	*s2;

	s2 = NULL;
	w = (t_world *)calloc(sizeof(t_world), 1);
	if (!w)
		return (NULL);
	w->light = point_light(color(1, 1, 1), point(-10, 10, -10));
	s1 = sphere();
	if (!s1)
	{
		free_world(&w);
		return (NULL);
	}
	m = default_material();
	s2 = set(s1, s2, m, w);
	if (s2 == NULL)
		return (NULL);
	return (w);
}

void	set_shape(t_world *w, t_shape *new_shape)
{
	t_shape	*w_shapes;

	if (!w || !new_shape)
	{
		printf("Error: set_shape: NULL parameter.\n");
		return ;
	}
	if (!w->shapes)
	{
		w->shapes = new_shape;
		return ;
	}
	w_shapes = w->shapes;
	while (w_shapes->next)
		w_shapes = w_shapes->next;
	w_shapes->next = new_shape;
}

void	free_world(t_world **w)
{
	t_world	*ptr;

	ptr = *w;
	free_point_light(&(ptr->light));
	free_shape(ptr->shapes);
	free(ptr);
	ptr = NULL;
	*w = NULL;
}

void	set_light(t_world *w, t_point_light *l)
{
	if (!w || !l)
	{
		printf("Error: set_light: NULL parameter.\n");
		return ;
	}
	free_point_light(&(w->light));
	w->light = l;
}
