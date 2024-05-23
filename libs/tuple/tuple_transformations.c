/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:33 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:53:56 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

void	transform_tuple(void *tuple, t_matrix *transformation)
{
	t_tuple		*t;
	t_matrix	*before;
	t_matrix	*after;

	after = NULL;
	before = NULL;
	t = (t_tuple *)tuple;
	if (!transformation || !t)
		return ;
	before = tuple_to_matrix(*t);
	if (!before)
	{
		free_matrix(&transformation);
		printf("Error 1: transform_tuple failed.\n");
		return ;
	}
	after = mult_matrices(*transformation, *before);
	if (!after)
	{
		free_matrices(transformation, before, NULL);
		printf("Error 2: transform_tuple failed.\n");
	}
	t->x = after->m[0][0];
	t->y = after->m[1][0];
	t->z = after->m[2][0];
	t->w = after->m[3][0];
	free_matrices(transformation, before, after, NULL);
}

t_matrix	*tuple_to_matrix(const t_tuple t)
{
	t_matrix	*new;

	new = matrix(4, 1);
	if (!new)
		return (NULL);
	new->m[0][0] = t.x;
	new->m[1][0] = t.y;
	new->m[2][0] = t.z;
	new->m[3][0] = t.w;
	return (new);
}

t_tuple	*matrix_to_tuple(const t_matrix m)
{
	if (m.rows != 4 || m.cols != 1)
	{
		printf("Error: matrix_to_tuple: matrix is not a 4x1 matrix.\n");
		return (NULL);
	}
	return (tuple(m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0]));
}