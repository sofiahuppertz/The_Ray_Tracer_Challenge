#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
} t_color;


t_color *color(double r, double g, double b);
t_color add_color(t_color c1, t_color c2);
t_color sub_color(t_color c1, t_color c2);
t_color scalar_color(t_color c1, double scalar);
t_color shur_product(t_color c1, t_color c2);
void print_color(t_color c);

# endif