/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:14:24 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "../pattern/pattern.h"

# define VACUUM 1.0
# define AIR 1.00029
# define WATER 0.333
# define GLASS 1.52
# define DIAMOND 2.417

typedef struct s_material
{
	t_pattern	*pattern;
	t_color		*ambient_color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	double		transparency;
	double		refrac_index;
}				t_material;

t_material		*default_material(void);
t_material		*material(t_pattern *pat, double ambient, double diffuse,
					double specular, double shininess);
t_material		*materialcpy(const t_material material);

void			print_material(const t_material material);

void			set_pattern(t_material *material, t_pattern *pattern);
void			set_ambient_color(t_material *material, t_color *color);
void			set_ambient(t_material *material, double ambient);
void			set_diffuse(t_material *material, double diffuse);
void			set_specular(t_material *material, double specular);
void			set_shininess(t_material *material, double shininess);
void			set_reflective(t_material *material, double reflective);
void			set_transparency(t_material *material, double transparency);
void			set_refrac_index(t_material *material, double refrac_index);
void			remove_pattern(t_material *material);

void			free_material(t_material **material);

#endif