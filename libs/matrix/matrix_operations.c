#include "matrix.h"

int equal_matrices(const t_matrix a, const t_matrix b)
{
    int i;
    int j;

    if (a.rows != b.rows || a.cols != b.cols)
        return 0;
    i = 0;
    while (i < a.rows)
    {
        j = 0;
        while (j < a.cols)
        {
            if (!equal(a.m[i][j], b.m[i][j]))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int is_square(const t_matrix m)
{
    return m.rows == m.cols;
}

t_matrix *mult_matrices(const t_matrix a, const t_matrix b)
{
    t_matrix *result;
    int i;
    int j;
    int k;

    if (a.cols != b.rows)
    {
        printf("Error: mult_matrices: incompatible matrices.\n");
        return NULL;
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
    return result;
}

void transpose(t_matrix **m)
{
    t_matrix *before;
    t_matrix *after;
    int i;
    int j;

    before = *m;
    after = matrix(before->cols, before->rows);
    if (!after)
    {
        free(*m);
        printf("Error: transpose: memory allocation failed.\n");
        return;
    }
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
    free_matrix(m);
    *m = after;
}

double determinant(const t_matrix m)
{
    double det;
    int i;

    det = 0;
    i = 0;
    if (!is_square(m))
    {
        printf("Error: determinant: matrix not square.\n");
        return -1;
    }
    if (m.rows == 2 && m.cols == 2)
        det  = m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0];
    else
    {
        while (i < m.cols)
        {
            det += m.m[0][i] * cofactor(m, 0, i);
            i++;
        }
    }
    return det;
}

double cofactor(const t_matrix m, const int row, const int col)
{
    if ((row + col) % 2 == 0)
        return minor(m, row, col);
    else
        return -minor(m, row, col);
}

double minor(t_matrix m, int row, int col)
{
    t_matrix *sub;
    double result;

    sub = submatrix(m, row, col);
    result = determinant(*sub);
    free_matrix(&sub);
    return result;
}

t_matrix *submatrix(const t_matrix m, const int row, const int col)
{
    t_matrix *sub;
    int i;
    int j;
    int i_sub;
    int j_sub;

    sub =  matrix(m.rows - 1, m.cols - 1);
    if (!sub)
        return NULL;
    i = 0;
    i_sub = 0;
    while(i < m.rows)
    {
        if (i == row)
            i++;
        else
        {
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
            i++;
            i_sub++;
        }
    }    
    return sub;
}

t_matrix *inverse(const t_matrix m)
{
    double det;
    double cof;
    int i;
    int j;
    t_matrix *inv;

    det = determinant(m);
    if (!is_square(m) || det == 0 )
    {
        printf("Stop: inverse: matrix is not invertible.\n");
        return NULL;
    }
    inv = matrix(m.rows, m.cols);
    i = 0;
    while (i < m.rows)
    {
        j = 0;
        while (j < m.cols)
        {
            cof = cofactor(m, i, j);
            inv->m[j][i] = cof / det;
            j++;
        }
        i++;
    }
    return inv;
}


t_matrix *matrixcpy(const t_matrix m)
{
    t_matrix *copy;
    int i;
    int j;

    copy = matrix(m.rows, m.cols);
    if (!copy)
    {
        printf("Error: matrixcpy: memory allocation failed.\n");
        return NULL;
    }
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
    return copy;
}