/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:27 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 16:12:36 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"


static int alloc_rows(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->rows)
	{
		matrix->m[i] = (double *)calloc(matrix->cols, sizeof(double));
		if (!matrix->m[i])
		{
			printf("Error: matrix: memory allocation failed.\n");
			free_matrix(&matrix);
			return 1;
		}
		i++;
	}
	matrix->m[i] = NULL;
	return 0;
}

t_matrix	*matrix(const int rows, const int cols)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)calloc(sizeof(t_matrix), 1);
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->m = (double **)calloc(sizeof(double *), (rows + 1));
	if (!matrix->m)
	{
		printf("Error: matrix: memory allocation failed.\n");
		free(matrix);
		return (NULL);
	}
	if (alloc_rows(matrix))
		return (NULL);
	return (matrix);
}

void	print_matrix(const t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			printf("%f ", matrix->m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_matrix(t_matrix **matrix)
{
	int	i;

	i = 0;
	while (i < (*matrix)->rows)
	{
		free((*matrix)->m[i]);
		(*matrix)->m[i] = NULL;
		i++;
	}
	free((*matrix)->m);
	(*matrix)->m = NULL;
	free(*matrix);
	*matrix = NULL;
}

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180);
}

void	free_matrices(t_matrix *initial, ...)
{
	va_list		ap;
	t_matrix	*m;

	va_start(ap, initial);
	m = initial;
	while (m)
	{
		free_matrix(&m);
		m = va_arg(ap, t_matrix *);
		if (!m)
			break ;
	}
	va_end(ap);
}
