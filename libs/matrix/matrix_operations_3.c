/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:30:10 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 16:25:53 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*test(const t_matrix m, const int col, t_matrix *sub,
		int indexes[2])
{
	int	j;
	int	j_sub;

	j = 0;
	j_sub = 0;
	while (j < m.cols)
	{
		if (j == col)
			j++;
		else
		{
			sub->m[indexes[1]][j_sub] = m.m[indexes[0]][j];
			j++;
			j_sub++;
		}
	}
	return (sub);
}

static void	calculate_submatrix(t_matrix *sub, const t_matrix m, const int row,
		const int col)
{
	int	indexes[2];

	indexes[0] = 0;
	indexes[1] = 0;
	while (indexes[0] < m.rows)
	{
		if (indexes[0] == row)
			indexes[0]++;
		else
		{
			sub = test(m, col, sub, indexes);
			indexes[0]++;
			indexes[1]++;
		}
	}
}

t_matrix	*submatrix(const t_matrix m, const int row, const int col)
{
	t_matrix	*sub;

	sub = matrix(m.rows - 1, m.cols - 1);
	if (!sub)
		return (NULL);
	calculate_submatrix(sub, m, row, col);
	return (sub);
}

static void	calculate_inverse_matrix(t_matrix *inv, const t_matrix m,
		double det)
{
	double	cof;
	int		i;
	int		j;

	i = -1;
	while (++i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			cof = cofactor(m, i, j);
			inv->m[j][i] = cof / det;
			j++;
		}
	}
}

t_matrix	*inverse(const t_matrix m)
{
	double		det;
	t_matrix	*inv;

	det = determinant(m);
	if (!is_square(m) || det == 0)
		return (NULL);
	inv = matrix(m.rows, m.cols);
	calculate_inverse_matrix(inv, m, det);
	return (inv);
}
