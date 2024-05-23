/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:09 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:37:16 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*raycpy(const t_ray r)
{
	t_ray	*cpy;
	t_tuple	*origin;
	t_tuple	*direction;

	origin = tuplecpy((const t_tuple)(*r.o));
	if (!origin)
	{
		printf("Error: raycpy: origin memory allocation failed.\n");
		return (NULL);
	}
	direction = tuplecpy((const t_tuple)(*r.di));
	if (!direction)
	{
		printf("Error: raycpy: direction memory allocation failed.\n");
		free(origin);
		return (NULL);
	}
	cpy = ray(origin, direction);
	return (cpy);
}
