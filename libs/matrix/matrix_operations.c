/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:19 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:28:11 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	equal_matrices(const t_matrix a, const t_matrix b)
{
	int	i;
	int	j;

	if (a.rows != b.rows || a.cols != b.cols)
		return (0);
	i = 0;
	while (i < a.rows)
	{
		j = 0;
		while (j < a.cols)
		{
			if (!equal(a.m[i][j], b.m[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_square(const t_matrix m)
{
	return (m.rows == m.cols);
}

t_matrix	*mult_matrices(const t_matrix a, const t_matrix b)
{
	t_matrix	*result;
	int			i;
	int			j;
	int			k;

	if (a.cols != b.rows)
	{
		printf("Error: mult_matrices: incompatible matrices.\n");
		return (NULL);
	}
	result = matrix(a.rows, b.cols);
	if (!result)
		return (NULL);
	i = 0;
	while (i < a.rows)
	{
		j = 0;
		while (j < b.cols)
		{
			k = 0;
			while (k < a.cols)
			{
				result->m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

double	determinant(const t_matrix m)
{
	double	det;
	int		i;

	det = 0;
	i = 0;
	if (!is_square(m))
	{
		printf("Error: determinant: matrix not square.\n");
		return (-1);
	}
	if (m.rows == 2 && m.cols == 2)
		det = m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0];
	else
	{
		while (i < m.cols)
		{
			det += m.m[0][i] * cofactor(m, 0, i);
			i++;
		}
	}
	return (det);
}
