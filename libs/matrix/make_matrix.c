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