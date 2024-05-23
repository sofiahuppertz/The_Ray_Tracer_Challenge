/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:52 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:49:42 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	*scene(void)
{
	static t_scene	*scene;

	if (!scene)
	{
		scene = (t_scene *)calloc(1, sizeof(t_scene));
		if (!scene)
		{
			printf("Error: Calloc failed in scene\n");
			return (NULL);
		}
		scene->material = default_material();
		scene->world = empty_world();
	}
	return (scene);
}
