#ifndef TUPLE_H
# define TUPLE_H

#include <math.h>
#include <stdio.h>


# define EPSILON 0.00001


typedef struct s_tuple
{
    double x;
    double y;
    double z;
    double w;
} t_tuple;


t_tuple point(double x, double y, double z);
t_tuple vector(double x, double y, double z);
t_tuple add_tuple(t_tuple a, t_tuple b);
t_tuple sub_tuple(t_tuple a, t_tuple b);
t_tuple neg_tuple(t_tuple a);
t_tuple scalar_tuple(t_tuple a, double scalar_tuple);
t_tuple norm(t_tuple a);
t_tuple cross(t_tuple a, t_tuple b);

// Later this function should belong to another library
int equal(double a, double b);

double dot(t_tuple a, t_tuple b);
double mag(t_tuple a);
void print_tuple(t_tuple a);



# endif