#ifndef MATRIX_H
# define MATRIX_H

#ifndef EPSILON
# define EPSILON 0.00001
#endif

#ifndef PI
#define PI 3.14159265358979323846
#endif

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_element
{
    POINT,
    VECTOR,
    IDK,
    RAY,
    CAMERA,
    PATTERN,
    SHAPE,
    SPHERE,
    PLANE,
    CYLINDRICAL
} t_elem;

typedef struct s_matrix {
    int rows;
    int cols;
    double **m;
} t_matrix;

typedef void (*t_transform_func)(void *, t_matrix *);

typedef struct s_tf
{
    t_elem type;
    t_transform_func transform;
} t_tf;


// Basic matrix functions
t_matrix *matrix(int rows, int cols);
void print_matrix(const t_matrix *matrix);
void  free_matrix(t_matrix **m);
void free_matrices(t_matrix *initial, ...);
double degrees_to_radians(double degrees);


// Matrix operations that change the matrix
t_matrix *transpose(t_matrix **m);


// Matrix operations that return a new matrix
t_matrix *inverse(const t_matrix m);
t_matrix *matrixcpy(const t_matrix m);
t_matrix *mult_matrices(const t_matrix a, const t_matrix b);
t_matrix *submatrix(const t_matrix m, int row, int col);


// Matrix operations that return a value
int equal_matrices(const t_matrix a, const t_matrix b);
int is_square(const t_matrix m);
double determinant(const t_matrix m);
double minor(const t_matrix m, int row, int col);
double cofactor(const t_matrix m, int row, int col);


//Matrix transformations
t_matrix *identity(unsigned int size);
t_matrix *translation(double x, double y, double z);
t_matrix *scaling(double x, double y, double z);
t_matrix *rotation_x(double rad);
t_matrix *rotation_y(double rad);
t_matrix *rotation_z(double rad);
t_matrix *rotation_matrix(double angle, double x, double y, double z);
t_matrix *shearing(double xy, double xz, double yx, double yz, double zx, double zy);
t_matrix *chain_tfs(t_matrix *initial, ...);

// Utility functions
int equal(const double a, const double b);

//Apply transformation to other objects
void transform(void *elem, t_matrix *transformation);

#endif