#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_color {
    double r;
    double g;
    double b;
} t_color;


t_color *color(double r, double g, double b);
t_color *black(void);
t_color *white(void);
t_color *colorcpy(const t_color c);
t_color *sum_color(const t_color c1, const t_color c2);
t_color *sub_color(const t_color c1, const t_color c2);
t_color *scalar_color(const t_color c1, double scalar);
t_color *shur_product(const t_color c1, const t_color c2);
t_color *average_colors(const t_color c1, const t_color c2);
t_color *add_colors(t_color *initial, ...);

double div_255(double color);

void print_color(const t_color c);

# endif