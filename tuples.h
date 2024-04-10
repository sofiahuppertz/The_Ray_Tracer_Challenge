#ifndef TUPLES_H
# define TUPLES_H

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
t_tuple add(t_tuple a, t_tuple b);
t_tuple sub(t_tuple a, t_tuple b);
t_tuple neg(t_tuple a);
t_tuple scalar(t_tuple a, double scalar);
t_tuple norm(t_tuple a);
t_tuple cross(t_tuple a, t_tuple b);
int equal(double a, double b);
double dot(t_tuple a, t_tuple b);
double mag(t_tuple a);
void print_tuple(t_tuple a);



# endif