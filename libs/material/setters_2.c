/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:11:53 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:12:30 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	set_reflective(t_material *material, double reflective)
{
	if (!material)
	{
		printf("Error: set_reflective: NULL parameter.\n");
		return ;
	}
	if (reflective <= 0.0)
		material->reflective = 0.0;
	if (reflective >= 1.0)
		material->reflective = 1.0;
	else
		material->reflective = reflective;
}

void	set_transparency(t_material *material, double transparency)
{
	if (!material)
	{
		printf("Error: set_transparency: NULL parameter.\n");
		return ;
	}
	if (transparency <= 0.0)
		material->transparency = 0.0;
	if (transparency >= 1.0)
		material->transparency = 1.0;
	else
		material->transparency = transparency;
}

void	set_refrac_index(t_material *material, double refrac_index)
{
	if (!material)
	{
		printf("Error: set_refrac_index: NULL parameter.\n");
		return ;
	}
	material->refrac_index = refrac_index;
}
