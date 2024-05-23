/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:10:17 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:10:56 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	print_material(const t_material material)
{
	if (material.pattern)
		print_pattern(*material.pattern);
	printf("Ambient: %f\n", material.ambient);
	if (material.ambient_color)
		print_color(*material.ambient_color);
	printf("Diffuse: %f\n", material.diffuse);
	printf("Specular: %f\n", material.specular);
	printf("Shininess: %f\n", material.shininess);
	printf("Reflective: %f\n", material.reflective);
	printf("Transparency: %f\n", material.transparency);
	printf("Refractive index: %f\n", material.refrac_index);
}

// void set_color(t_material *material, t_color *color)
//{
//     if (!material || !color)
//     {
//         printf("Error: set_color: NULL parameter.\n");
//         return ;
//     }
//     free(material->color);
//     material->color = color;
// }

void	set_pattern(t_material *material, t_pattern *pattern)
{
	if (!material || !pattern)
	{
		printf("Error: set_pattern: NULL parameter.\n");
		return ;
	}
	if (material->pattern)
		free_pattern(&material->pattern);
	material->pattern = pattern;
}

void	remove_pattern(t_material *material)
{
	if (!material)
	{
		printf("Error: remove_pattern: NULL parameter.\n");
		return ;
	}
	if (material->pattern)
		free_pattern(&material->pattern);
}

void	free_material(t_material **material)
{
	if (!material || !*material)
		return ;
	if ((*material)->pattern)
		free_pattern(&(*material)->pattern);
	free((*material)->ambient_color);
	free(*material);
	*material = NULL;
}
