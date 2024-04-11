#include "../declarations/tuple.h"

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

t_tuple add_tuple(t_tuple a, t_tuple b)
{
    t_tuple sum = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
    if (sum.w > 1.0)
        printf("Error: add_tuple two points.\n");
    return sum;
}

t_tuple sub_tuple(t_tuple a, t_tuple b)
{
    t_tuple diff = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
    if (diff.w < 0.0)
        printf("Error: sub_tuple point to vector.\n");
    return diff;
}

t_tuple neg_tuple(t_tuple a)
{
    t_tuple neg_tuple = {-a.x, -a.y, -a.z, -a.w};
    return neg_tuple;
}

t_tuple scalar_tuple(t_tuple a, double scalar_tuple)
{
    t_tuple product = {a.x * scalar_tuple, a.y * scalar_tuple, a.z * scalar_tuple, a.w * scalar_tuple};
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
        printf("Error: dot product: passing point  to vector operation.\n");
    double dot_product = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return dot_product;
}

t_tuple cross(t_tuple a, t_tuple b)
{
    if (a.w == 1.0 || b.w == 1.0)
        printf("Error: cross product: passing point to vector operation.\n");
    t_tuple cross_product = vector(a.y * b.z - a.z * b.y,
                                    a.z * b.x - a.x * b.z,
                                    a.x * b.y - a.y * b.x);
    return cross_product;
}

void print_tuple(t_tuple a)
{
    printf("x: %f, y: %f, z: %f, w: %f\n", a.x, a.y, a.z, a.w);
}
