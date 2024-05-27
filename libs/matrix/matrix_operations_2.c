/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:27:29 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 15:42:58 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void copy_values(t_matrix *after, t_matrix *before)
{
	int	i;
	int	j;

	i = 0;
	while (i < before->rows)
	{
		j = 0;
		while (j < before->cols)
		{
			after->m[j][i] = before->m[i][j];
			j++;
		}
		i++;
	}
}

t_matrix	*transpose(t_matrix **m)
{
	t_matrix	*before;
	t_matrix	*after;

	before = *m;
	after = matrix(before->cols, before->rows);
	if (!after)
	{
		free(*m);
		return (NULL);
	}
	copy_values(after, before);
	free_matrix(m);
	*m = after;
	return (*m);
}

double	cofactor(const t_matrix m, const int row, const int col)
{
	if ((row + col) % 2 == 0)
		return (compute_minor(m, row, col));
	else
		return (-compute_minor(m, row, col));
}

double	compute_minor(t_matrix m, int row, int col)
{
	t_matrix	*sub;
	double		result;

	sub = submatrix(m, row, col);
	result = determinant(*sub);
	free_matrix(&sub);
	return (result);
}

t_matrix	*matrixcpy(const t_matrix m)
{
	t_matrix	*copy;
	int			i;
	int			j;

	copy = NULL;
	copy = matrix(m.rows, m.cols);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			copy->m[i][j] = m.m[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}
