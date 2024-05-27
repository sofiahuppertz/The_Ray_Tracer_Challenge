/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:30:10 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 15:36:21 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*test(const t_matrix m, const int col, t_matrix *sub, int i_sub, int i)
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
			sub->m[i_sub][j_sub] = m.m[i][j];
			j++;
			j_sub++;
		}
	}
	return (sub);
}

t_matrix	*submatrix(const t_matrix m, const int row, const int col)
{
	t_matrix	*sub;
	int			i;
	int			i_sub;

	sub = matrix(m.rows - 1, m.cols - 1);
	if (!sub)
		return (NULL);
	i = 0;
	i_sub = 0;
	while (i < m.rows)
	{
		if (i == row)
			i++;
		else
		{
			sub = test(m, col, sub, i_sub, i);
			i++;
			i_sub++;
		}
	}
	return (sub);
}

t_matrix	*inverse(const t_matrix m)
{
	double		det;
	double		cof;
	int			i;
	int			j;
	t_matrix	*inv;

	det = determinant(m);
	if (!is_square(m) || det == 0)
	{
		printf("Stop: inverse: matrix is not invertible.\n");
		return (NULL);
	}
	inv = matrix(m.rows, m.cols);
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
	return (inv);
}
