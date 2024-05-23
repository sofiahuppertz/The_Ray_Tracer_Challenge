/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:28:17 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 13:28:54 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*sub_color(const t_color c1, const t_color c2)
{
	t_color	*diff;

	diff = NULL;
	diff = color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
	if (!diff)
		printf("Error: sub_color: failed.\n");
	return (diff);
}

t_color	*scalar_color(const t_color c1, double scalar)
{
	t_color	*product;

	product = NULL;
	product = color(c1.r * scalar, c1.g * scalar, c1.b * scalar);
	if (!product)
		printf("Error: scalar_color: failed.\n");
	return (product);
}

t_color	*shur_product(const t_color c1, const t_color c2)
{
	t_color	*product;

	product = NULL;
	product = color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
	if (!product)
	{
		printf("Error: shur_product: failed.\n");
	}
	return (product);
}

t_color	*average_colors(const t_color c1, const t_color c2)
{
	t_color	*average;

	average = color((c1.r + c2.r) / 2, (c1.g + c2.g) / 2, (c1.b + c2.b) / 2);
	return (average);
}

void	print_color(const t_color c)
{
	printf("(%f, %f, %f)\n", c.r, c.g, c.b);
}
