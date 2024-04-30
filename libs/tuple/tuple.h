#ifndef TUPLE_H
# define TUPLE_H

#include "../matrix/matrix.h"


typedef struct s_tuple
{
    t_tf tf;
    double x;
    double y;
    double z;
    double w;
} t_tuple;

// Operations that return a new tuple
t_tuple *tuple(const double x, const double y, const double z, const double w);
t_tuple *tuplecpy(const t_tuple a);
t_tuple *point(const double x, const double y, const double z);
t_tuple *vector(const double x, const double y, const double z);
t_tuple *add_tuple(const t_tuple a, const t_tuple b);
t_tuple *sub_tuple(const t_tuple a, const t_tuple b);
t_tuple *cross(const t_tuple a, const t_tuple b);
t_tuple *reflection(const t_tuple in, const t_tuple normal);

// Operations that modify the tuple
t_tuple *neg_tuple(t_tuple *a);
t_tuple *scalar_tuple(t_tuple *a, const double scalar);
t_tuple *norm(t_tuple *a);
void tupletype(t_tuple *a);

// Operations that return a value
double dot(const t_tuple a, const t_tuple b);
double mag(const t_tuple a);

// Operations that involve matrices
t_matrix *tuple_to_matrix(const t_tuple t);
t_tuple *matrix_to_tuple(const t_matrix m);
void transform_tuple(void *tuple, t_matrix *transformation);

void print_tuple(const t_tuple *a);
void free_tuples(t_tuple **initial, ...);


#endif