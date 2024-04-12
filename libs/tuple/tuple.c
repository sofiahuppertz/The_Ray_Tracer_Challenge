#include "tuple.h"

t_tuple *point(const double x, const double y, const double z)
{
    t_tuple *point;
    
    point = (t_tuple*)calloc(1, sizeof(t_tuple));
    if (!point)
    {
        printf("Error: point memory allocation failed.\n");
        return NULL;
    }
    point->x = x;
    point->y = y;
    point->z = z;
    point->w = 1.0;
    return point;
}

t_tuple *vector(const double x, const double y, const double z)
{
    t_tuple *vector;
    
    vector = (t_tuple*)calloc(1, sizeof(t_tuple));
    if (!vector)
    {
        printf("Error: vector memory allocation failed.\n");
        return NULL;
    }
    vector->x = x;
    vector->y = y;
    vector->z = z;
    vector->w = 0.0;
    return vector;
}

int equal(const double a, const double b)
{
    if (fabs(a - b) < EPSILON)
        return 1;
    else
        return 0;
}

t_tuple *add_tuple(const t_tuple a, const t_tuple b)
{
    t_tuple *sum;
    sum = (t_tuple *)calloc(1, sizeof(t_tuple));
    if (!sum)
    {
        printf("Error: add_tuple memory allocation failed.\n");
        return NULL;
    }
    sum->x = a.x + b.x;
    sum->y = a.y + b.y;
    sum->z = a.z + b.z;
    sum->w = a.w + b.w;
    if (sum->w > 1.0)
        printf("Error: add_tuple two points.\n");
    return sum;
}

t_tuple *sub_tuple(const t_tuple a, const t_tuple b)
{
    t_tuple *diff;
    diff = (t_tuple *)calloc(1, sizeof(t_tuple));
    if (!diff)
    {
        printf("Error: sub_tuple memory allocation failed.\n");
        return NULL;
    }
    diff->x = a.x - b.x;
    diff->y = a.y - b.y;
    diff->z = a.z - b.z;
    diff->w = a.w - b.w;
    if (diff->w > 1.0)
        printf("Error: sub_tuple points to vector.\n");
    return diff;
}

t_tuple *neg_tuple(const t_tuple a)
{
    t_tuple *neg;
    
    neg = (t_tuple *)calloc(1, sizeof(t_tuple));
    if (!neg)
    {
        printf("Error: neg_tuple memory allocation failed.\n");
        return NULL;
    }
    neg->x = -a.x;
    neg->y = -a.y;
    neg->z = -a.z;
    neg->w = -a.w;
    return neg;
}

t_tuple *scalar_tuple(const t_tuple a, const double scalar_tuple)
{
    t_tuple *product;

    product = (t_tuple *)calloc(1, sizeof(t_tuple));
    if (!product)
    {
        printf("Error: scalar_tuple memory allocation failed.\n");
        return NULL;
    }
    product->x = a.x * scalar_tuple;
    product->y = a.y * scalar_tuple;
    product->z = a.z * scalar_tuple;
    product->w = a.w * scalar_tuple;
    return product;
}

double mag(const t_tuple a)
{
    double magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
    return magnitude;
}

t_tuple *norm(const t_tuple a)
{
    double m;
    t_tuple *norm;
    
    m = mag(a);
    norm = scalar_tuple(a, 1 / m);
    if (!norm)
    {
        printf("Error: norm failed.\n");
        return NULL;
    }
    return norm;
}

double dot(const t_tuple a, const t_tuple b)
{
    double prod;

    if (a.w == 1.0 || b.w == 1.0)
        printf("Error: dot product: passing point  to vector operation.\n");
    prod = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return prod;
}

t_tuple *cross(const t_tuple a, const t_tuple b)
{
    t_tuple *prod;
    
    if (a.w == 1.0 || b.w == 1.0)
        printf("Error: cross product: passing point to vector operation.\n");
    prod = vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    return prod;
}

void print_tuple(const t_tuple a)
{
    printf("x: %f, y: %f, z: %f, w: %f\n", a.x, a.y, a.z, a.w);
}
