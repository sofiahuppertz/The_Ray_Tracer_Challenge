/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:29:07 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 13:29:35 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*colorcpy(const t_color c)
{
	t_color	*cpy;

	cpy = (t_color *)calloc(1, sizeof(t_color));
	if (!cpy)
	{
		printf("Error: colorcpy: unable to allocate memory.\n");
		return (NULL);
	}
	cpy->r = c.r;
	cpy->g = c.g;
	cpy->b = c.b;
	return (cpy);
}

t_color	*black(void)
{
	return (color(0, 0, 0));
}

t_color	*white(void)
{
	return (color(1, 1, 1));
}
