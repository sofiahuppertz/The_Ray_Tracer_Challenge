/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:46 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:47:59 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	*gradient(t_color *a, t_color *b)
{
	t_pattern	*gradient;

	gradient = (t_pattern *)calloc(1, sizeof(t_pattern));
	if (!gradient)
	{
		printf("Error: gradient calloc failed.\n");
	}
	pattern(a, b, gradient);
	gradient->local_pattern = gradient_at;
	return (gradient);
}

t_color	*gradient_at(void *pattern, const t_tuple point)
{
	t_pattern *gradient;
	t_color *color;
	t_color *distance;
	double fraction;

	gradient = (t_pattern *)pattern;
	distance = sub_color(*gradient->b, *gradient->a);
	fraction = point.x - floor(point.x);
	color = add_colors(colorcpy(*gradient->a), scalar_color(*distance,
				fraction), NULL);
	free(distance);
	return (color);
}