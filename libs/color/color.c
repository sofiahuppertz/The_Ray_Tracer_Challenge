#include "color.h"


t_color *color(double r, double g, double b)
{
    t_color *color = (t_color *)calloc(1, sizeof(t_color));
    color->r = r;
    color->g = g;
    color->b = b;
    return color;
}


t_color add_color(t_color c1, t_color c2)
{
    t_color sum = {c1.r + c2.r, c1.g + c2.g, c1.b + c2.b};
    return sum;
}

t_color sub_color(t_color c1, t_color c2)
{
    t_color diff = {c1.r - c2.r, c1.g - c2.g, c1.b - c2.b};
    return diff;
}

t_color scalar_color(t_color c1, double scalar)
{
    print_color(c1);
    t_color product = {c1.r * scalar, c1.g * scalar, c1.b * scalar};
    return product;
}

t_color shur_product(t_color c1, t_color c2)
{
    t_color product = {c1.r * c2.r, c1.g * c2.g, c1.b * c2.b};
    return product;
}

void print_color(t_color c)
{
    printf("(%u, %u, %u)\n", c.r, c.g, c.b);
}