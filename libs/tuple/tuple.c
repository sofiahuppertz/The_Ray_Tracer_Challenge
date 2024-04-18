#include "tuple.h"


t_tuple *tuple(const double x, const double y, const double z, const double w)
{
    t_tuple *tuple;
    
    tuple = (t_tuple*)calloc(1, sizeof(t_tuple));
    if (!tuple)
    {
        printf("Error: tuple memory allocation failed.\n");
        return NULL;
    }
    tuple->x = x;
    tuple->y = y;
    tuple->z = z;
    tuple->w = w;
    return tuple;
}


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

void neg_tuple(t_tuple *neg)
{
    if (!neg)
    {
        printf("Error: neg_tuple: null pointer.\n");
        return;
    }
    neg->x = -neg->x;
    neg->y = -neg->y;
    neg->z = -neg->z;
    neg->w = -neg->w;
}

void scalar_tuple(t_tuple *a, const double scalar)
{
    if (!a)
    {
        printf("Error: scalar_tuple: null pointer.\n");
        return;
    }
    a->x *= scalar;
    a->y *= scalar;
    a->z *= scalar;
    a->w *= scalar;
}

double mag(const t_tuple a)
{
    double magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
    return magnitude;
}

void norm(t_tuple *a)
{
    double m;

    if (!a)
    {
        printf("Error: norm: null pointer.\n");
        return;
    }
    m = mag(*a);
    scalar_tuple(a, 1 / m);
    if (!a)
        printf("Error: norm: operation failed.\n");
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

void print_tuple(const t_tuple *a)
{
    printf("x: %f, y: %f, z: %f, w: %f\n", a->x, a->y, a->z, a->w);
}


t_tuple *tuplecpy(const t_tuple a)
{
    t_tuple *dup;
    dup = tuple(a.x, a.y, a.z, a.w);
    if (!dup)
        printf("Error: tuplecpy: operation failed.\n");
    return dup;
}

t_tuple *reflection(const t_tuple in, const t_tuple normal)
{
    t_tuple *reflect;
    t_tuple *temp;
    double dot_product;

    dot_product = dot(in, normal);
    temp = tuplecpy(normal);
    scalar_tuple(temp, 2 * dot_product);
    reflect = sub_tuple(in, (const t_tuple)*temp);
    free(temp);
    return reflect;
}
