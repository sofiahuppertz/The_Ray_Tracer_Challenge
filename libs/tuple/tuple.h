#ifndef TUPLE_H
# define TUPLE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


# define EPSILON 0.00001


typedef struct s_tuple
{
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
void neg_tuple(t_tuple *a);
void scalar_tuple(t_tuple *a, const double scalar);
void norm(t_tuple *a);

// Operations that return a value
double dot(const t_tuple a, const t_tuple b);
double mag(const t_tuple a);


void print_tuple(const t_tuple *a);

// Later this function should belong to another library?
int equal(const double a, const double b);

# endif