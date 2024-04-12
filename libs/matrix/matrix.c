#include "matrix.h"

t_matrix *matrix(const int rows, const int cols)
{
    int i;
    t_matrix *matrix;

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
    i = 0;
    while (i < rows)
    {
        matrix->m[i] = (double *)calloc(cols, sizeof(double));
        if (!matrix->m[i])
        {
            printf("Error: matrix: memory allocation failed.\n");
            free_matrix(matrix);
            return (NULL);
        }
        i++;
    }
    matrix->m[i] = NULL;
    return matrix;
}

void print_matrix(const t_matrix matrix)
{
    int i;
    int j;

    i = 0;
    while (i < matrix.rows)
    {
        j = 0;
        while (j < matrix.cols)
        {
            printf("%f ", matrix.m[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void free_matrix(t_matrix *matrix)
{
    int i;

    i = 0;   
    while (i < matrix->rows)
    {
        free(matrix->m[i]);
        matrix->m[i] = NULL;
        i++;
    }
    free(matrix->m);
    matrix->m = NULL;
    free(matrix);
    matrix = NULL;
}

t_matrix *tuple_to_matrix(const t_tuple t)
{
    t_matrix *new;
    
    new = matrix(4, 1);
    if (!new)
        return NULL;
    new->m[0][0] = t.x;
    new->m[1][0] = t.y;
    new->m[2][0] = t.z;
    new->m[3][0] = t.w;
    return new;
}

double degrees_to_radians(double degrees)
{
    return degrees * M_PI / 180;
}