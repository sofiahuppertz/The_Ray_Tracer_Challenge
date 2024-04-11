#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

typedef struct s_color {
    float r;
    float g;
    float b;
} t_color;


t_color add_color(t_color c1, t_color c2);
t_color sub_color(t_color c1, t_color c2);
t_color scalar_color(t_color c1, float scalar);
t_color shur_product(t_color c1, t_color c2);
void print_color(t_color c);

# endif