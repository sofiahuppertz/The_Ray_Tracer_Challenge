/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:39:42 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:48:32 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_attributes	*stripe(t_color *a, t_color *b, double width, double r_z)
{
	t_attributes	*attr;

	if (!a || !b)
		return (NULL);
	attr = new_attr();
	if (!attr)
		return (NULL);
	attr->key = (char *)calloc(7, sizeof(char));
	if (!attr->key)
		return (NULL);
	strcpy(attr->key, "stripe");
	attr->value = stripe_pattern(a, b);
	transform(attr->value, chain_tfs(scaling(width, width, width),
			rotation_z(degrees_to_radians(r_z)), NULL));
	return (attr);
}

t_attributes	*rfl(double reflectivity)
{
	t_attributes	*attr;

	attr = double_attr();
	if (!attr)
	{
		printf("Error: rfl: failed.\n");
		return (NULL);
	}
	strcpy(attr->key, "rfl");
	*(double *)attr->value = reflectivity;
	return (attr);
}

t_attributes	*rfr(double refractive_index)
{
	t_attributes	*attr;

	attr = double_attr();
	if (!attr)
	{
		printf("Error: rfr: failed.\n");
		return (NULL);
	}
	strcpy(attr->key, "rfr");
	*(double *)attr->value = refractive_index;
	return (attr);
}

t_attributes	*tsy(double transparency)
{
	t_attributes	*attr;

	attr = double_attr();
	if (!attr)
	{
		printf("Error: try: failed.\n");
		return (NULL);
	}
	strcpy(attr->key, "tsy");
	*(double *)attr->value = transparency;
	return (attr);
}
