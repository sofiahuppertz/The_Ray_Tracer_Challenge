#include "color.h"


t_color *color(double r, double g, double b)
{
    t_color *color = (t_color *)calloc(1, sizeof(t_color));
    color->r = r;
    color->g = g;
    color->b = b;
    return color;
}


t_color *sum_color(const t_color c1, const t_color c2)
{
    t_color *sum;

    sum = NULL;
    sum = color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    if (!sum)
        printf("Error: sum_color: failed.\n");
    return sum;
}

t_color *add_colors(t_color *initial, ...)
{
    t_color *result;
    t_color *next_add;
    va_list args;

    if (!initial)
    {
        printf("Error: add_colors: initial null pointer.\n");
        return (NULL);
    }
    result = colorcpy(*initial);
    va_start(args, initial);
    while (1)
    {
        next_add = va_arg(args, t_color *);
        if (next_add == NULL)
            break;
        result->r += next_add->r;
        result->g += next_add->g;
        result->b += next_add->b;
        free(next_add);
    }
    va_end(args);
    free(initial);
    return result;
}

t_color *sub_color(const t_color c1, const t_color c2)
{
    t_color *diff;

    diff = NULL;
    diff = color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
    if (!diff)
        printf("Error: sub_color: failed.\n");
    return diff;
}

t_color *scalar_color(const t_color c1, double scalar)
{ 
    t_color *product;

    product = NULL;
    product = color(c1.r * scalar, c1.g * scalar, c1.b * scalar);
    if (!product)
        printf("Error: scalar_color: failed.\n");
    return product;
}

t_color *shur_product(const t_color c1, const t_color c2)
{
    t_color *product;
    
    product = NULL;
    product = color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
    if (!product)
    {
        printf("Error: shur_product: failed.\n");
    }
    return product;
}

t_color *average_colors(const t_color c1, const t_color c2)
{
    t_color *average;

    average = color((c1.r + c2.r) / 2, (c1.g + c2.g) / 2, (c1.b + c2.b) / 2);
    return average;

}

void print_color(const t_color c)
{
    printf("(%f, %f, %f)\n", c.r, c.g, c.b);
}

t_color *colorcpy(const t_color c)
{
    t_color *cpy;
    
    cpy = (t_color *)calloc(1, sizeof(t_color));
    if (!cpy)
    {
        printf("Error: colorcpy: unable to allocate memory.\n");
        return (NULL);
    }
    cpy->r = c.r;
    cpy->g = c.g;
    cpy->b = c.b;
    return cpy;
}

t_color *black(void)
{
    return color(0, 0, 0);
}

t_color *white(void)
{
    return color(1, 1, 1);
}