#include "tuples.h"
#include <stdio.h>



int tuples(void)
{
    t_tuple v = vector(4.3, -4.2, 3.1);
    printf("vector v:\n");
    print_tuple(v);

    t_tuple p = point(4.3, -4.2, 3.1);
    printf("point p:\n");
    print_tuple(p);


    int a = equal(4.33313331, 4.33333332);
    printf("a: %d\n", a);

    t_tuple res;
    t_tuple p1 = point(3, 2, 1);
    t_tuple p2 = point(5, 6, 7);
    t_tuple v1 = vector(1, -2, 3);
    t_tuple v2 = vector(5, 6, 7);

    printf("Adding a vector to a point\n");
    res = add(p1, v1);
    print_tuple(res);

    printf("Addind two points(not allowed)\n");
    res = add(p1, p2);
    print_tuple(res);

    printf("Substracting two points\n");
    res = sub(p1, p2);
    print_tuple(res);

    printf("Substracting a vector from a point\n");
    res = sub(p1, v2);
    print_tuple(res);

    printf("Substracting two vectors\n");
    res = sub(v1, v2);
    print_tuple(res);

    printf("Substracting a point from a vector(not allowed)\n");
    res = sub(v1, p2);
    print_tuple(res);

    printf("Negating a vector\n");
    print_tuple(v1);
    res = neg(v1);
    print_tuple(res);


    printf("Multiplying a vector by a scalar\n");
    print_tuple(v1);
    res = scalar(v1, 3.5);
    print_tuple(res);

    printf("Multiplying a vector by a fraction\n");
    print_tuple(v1);
    res = scalar(v1, 0.5);
    print_tuple(res);

    printf("Magnitude of a vector\n");
    t_tuple v3 = vector(1, 0, 0);
    printf("Magnitude: %f\n", mag(v3));

    v3 = vector(0, 1, 0);
    printf("Magnitude: %f\n", mag(v3));

    v3 = vector(0, 0, 1);
    printf("Magnitude: %f\n", mag(v3));

    v3 = vector(-1, -2, -3);
    printf("Magnitude: %f\n", mag(v3));

    printf("Normalizing a vector\n");
    t_tuple v4 = vector(4, 0, 0);
    print_tuple(norm(v4));

    v4 = vector(1, 2, 3);
    print_tuple(norm(v4));

    printf("Dot product of two vectors\n");
    double dot_p = dot(vector(1, 2, 3), vector(2, 3, 4));
    printf("Dot product (should be 20): %f\n", dot_p);

    printf("Cross product of two vectors\n");

    printf("Cross product (should be (-1, 2, -1))\n");
    print_tuple(cross(vector(1, 2, 3), vector(2, 3, 4)));

    printf("Cross product (should be (1, -2, 1))\n");
    print_tuple(cross(vector(2, 3, 4), vector(1, 2, 3)));




}