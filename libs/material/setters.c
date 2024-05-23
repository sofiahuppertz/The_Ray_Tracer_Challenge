/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:13 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:11:48 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	set_ambient(t_material *material, double ambient)
{
	if (!material)
	{
		printf("Error: set_ambient: NULL parameter.\n");
		return ;
	}
	if (ambient <= 0.0)
		material->ambient = 0.0;
	else
		material->ambient = ambient;
}

void	set_ambient_color(t_material *material, t_color *color)
{
	if (!material || !color)
	{
		printf("Error: set_ambient_color: NULL parameter.\n");
		return ;
	}
	if (material->ambient_color)
		free(material->ambient_color);
	material->ambient_color = color;
}

void	set_diffuse(t_material *material, double diffuse)
{
	if (!material)
	{
		printf("Error: set_diffuse: NULL parameter.\n");
		return ;
	}
	if (diffuse <= 0.0)
		material->diffuse = 0.0;
	else
		material->diffuse = diffuse;
}

void	set_specular(t_material *material, double specular)
{
	if (!material)
	{
		printf("Error: set_specular: NULL parameter.\n");
		return ;
	}
	if (specular <= 0.0)
		material->specular = 0.0;
	else
		material->specular = specular;
}

void	set_shininess(t_material *material, double shininess)
{
	if (!material)
	{
		printf("Error: set_shininess: NULL parameter.\n");
		return ;
	}
	if (shininess <= 10.0)
		material->shininess = 10.0;
	else if (shininess >= 200.0)
		material->shininess = 200.0;
	else
		material->shininess = shininess;
}
