/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:16 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 13:29:17 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

double	div_255(double color)
{
	return (color / 255.0);
}

t_color	*color(double r, double g, double b)
{
	t_color	*color;

	color = (t_color *)calloc(1, sizeof(t_color));
	if (!color)
	{
		printf("Error: color: failed to allocate memory.\n");
		return (NULL);
	}
	color->r = r;
	if (r >= 1)
		color->r = 1;
	color->g = g;
	if (g >= 1)
		color->g = 1;
	color->b = b;
	if (b >= 1)
		color->b = 1;
	return (color);
}

t_color	*sum_color(const t_color c1, const t_color c2)
{
	t_color	*sum;

	sum = NULL;
	sum = color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
	if (!sum)
		printf("Error: sum_color: failed.\n");
	return (sum);
}

t_color	*add_colors(t_color *initial, ...)
{
	t_color	*result;
	t_color	*next_add;
	va_list	args;

	if (!initial)
	{
		printf("Error: add_colors: initial null pointer.\n");
		return (NULL);
	}
	result = colorcpy(*initial);
	va_start(args, initial);
	while (1)
	{
		next_add = va_arg(args, t_color *);
		if (next_add == NULL)
			break ;
		result->r += next_add->r;
		if (result->r > 1)
			result->r = 1;
		result->g += next_add->g;
		if (result->g > 1)
			result->g = 1;
		result->b += next_add->b;
		if (result->b > 1)
			result->b = 1;
		free(next_add);
	}
	va_end(args);
	free(initial);
	return (result);
}
