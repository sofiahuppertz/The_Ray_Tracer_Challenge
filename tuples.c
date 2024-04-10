#include "tuples.h"

t_tuple point(double x, double y, double z)
{
    t_tuple point = {x, y, z, 1.0};
    return point;
}

t_tuple vector(double x, double y, double z)
{
    t_tuple vector = {x, y, z, 0.0};
    return vector;
}

int equal(double a, double b)
{
    if (fabs(a - b) < EPSILON)
        return 1;
    else
        return 0;
}

t_tuple add(t_tuple a, t_tuple b)
{
    t_tuple sum = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
    if (sum.w > 1.0)
        printf("Error: addition of two points.\n");
    return sum;
}

t_tuple sub(t_tuple a, t_tuple b)
{
    t_tuple diff = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
    if (diff.w < 0.0)
        printf("Error: substracting a point from a vector.\n");
    return diff;
}

t_tuple neg(t_tuple a)
{
    t_tuple neg = {-a.x, -a.y, -a.z, -a.w};
    return neg;
}

t_tuple scalar(t_tuple a, double scalar)
{
    t_tuple product = {a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar};
    return product;
}

double mag(t_tuple a)
{
    double magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
    return magnitude;
}

t_tuple norm(t_tuple a)
{
    double magnitude = mag(a);
    t_tuple normalized = {a.x / magnitude, a.y / magnitude, a.z / magnitude, a.w / magnitude};
    return normalized;
}

double dot(t_tuple a, t_tuple b)
{
    if (a.w == 1.0 || b.w == 1.0)
        printf("Error: dot product: passing point a vector operation.\n");
    double dot_product = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return dot_product;
}

t_tuple cross(t_tuple a, t_tuple b)
{
    if (a.w == 1.0 || b.w == 1.0)
        printf("Error: cross product: passing point a vector operation.\n");
    t_tuple cross_product = vector(a.y * b.z - a.z * b.y,
                                    a.z * b.x - a.x * b.z,
                                    a.x * b.y - a.y * b.x);
    return cross_product;
}

void print_tuple(t_tuple a)
{
    printf("x: %f, y: %f, z: %f, w: %f\n", a.x, a.y, a.z, a.w);
}
