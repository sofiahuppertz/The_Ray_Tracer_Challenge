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


t_tuple *point(const double x, const double y, const double z);
t_tuple *vector(const double x, const double y, const double z);
t_tuple *add_tuple(const t_tuple a, const t_tuple b);
t_tuple *sub_tuple(const t_tuple a, const t_tuple b);
t_tuple *neg_tuple(const t_tuple a);
t_tuple *scalar_tuple(const t_tuple a,const double scalar_tuple);
t_tuple *norm(const t_tuple a);
t_tuple *cross(const t_tuple a, const t_tuple b);

// Later this function should belong to another library
int equal(const double a, const double b);

double dot(const t_tuple a, const t_tuple b);
double mag(const t_tuple a);
void print_tuple(const t_tuple a);



# endif