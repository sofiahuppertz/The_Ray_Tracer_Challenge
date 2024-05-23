/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:22:11 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*identity(const unsigned int size)
{
	t_matrix		*id;
	unsigned int	i;
	unsigned int	j;

	id = matrix(size, size);
	if (!id)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				id->m[i][j] = 1;
			j++;
		}
		i++;
	}
	return (id);
}

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*translation;

	translation = identity(4);
	if (!translation)
		return (NULL);
	translation->m[0][3] = x;
	translation->m[1][3] = y;
	translation->m[2][3] = z;
	return (translation);
}

t_matrix	*scaling(double x, double y, double z)
{
	t_matrix	*scaling;

	scaling = identity(4);
	if (!scaling)
		return (NULL);
	scaling->m[0][0] = x;
	scaling->m[1][1] = y;
	scaling->m[2][2] = z;
	return (scaling);
}

t_matrix	*rotation_x(double rad)
{
	t_matrix	*rotation;

	rotation = identity(4);
	if (!rotation)
		return (NULL);
	rotation->m[1][1] = cos(rad);
	rotation->m[1][2] = -sin(rad);
	rotation->m[2][1] = sin(rad);
	rotation->m[2][2] = cos(rad);
	return (rotation);
}

t_matrix	*rotation_y(double rad)
{
	t_matrix	*rotation;

	rotation = identity(4);
	if (!rotation)
		return (NULL);
	rotation->m[0][0] = cos(rad);
	rotation->m[0][2] = sin(rad);
	rotation->m[2][0] = -sin(rad);
	rotation->m[2][2] = cos(rad);
	return (rotation);
}
