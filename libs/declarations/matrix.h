#ifndef MATRIX_H
# define MATRIX_H

#include "tuple.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_matrix {
    int rows;
    int cols;
    double **m;
} t_matrix;


// Basic matrix functions
t_matrix matrix(int rows, int cols);
t_matrix tuple_to_matrix(const t_tuple t);
void print_matrix(const t_matrix);
void  free_matrix(t_matrix);


// Matrix operations
t_matrix mult_matrices(const t_matrix a, const t_matrix b);
t_matrix transpose(const t_matrix m);
t_matrix submatrix(const t_matrix m, int row, int col);
t_matrix inverse(const t_matrix m);
t_matrix identity(unsigned int size);
int equal_matrices(const t_matrix a, const t_matrix b);
int is_square(const t_matrix m);
double determinant(const t_matrix m);
double minor(const t_matrix m, int row, int col);
double cofactor(const t_matrix m, int row, int col);



//Matrix transformations


# endif