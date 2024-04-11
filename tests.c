#include "libs/declarations/tuple.h"
#include "libs/declarations/color.h"
#include "libs/declarations/matrix.h"
#include <stdio.h>



int main(void){

    t_matrix m = matrix(4, 4);

    m.m[0][0] = 8;
    m.m[0][1] = -5;
    m.m[0][2] = 9;
    m.m[0][3] = 2;
    m.m[1][0] = 7;  
    m.m[1][1] = 5;
    m.m[1][2] = 6;
    m.m[1][3] = 1;
    m.m[2][0] = -6;
    m.m[2][1] = 0;
    m.m[2][2] = 9;
    m.m[2][3] = 6;
    m.m[3][0] = -3;
    m.m[3][1] = 0;
    m.m[3][2] = -9;
    m.m[3][3] = -4;

    t_matrix inv_m = inverse(m);

    t_tuple v = vector(1, 2, 3);

    t_matrix m2 = tuple_to_matrix(v);

    t_matrix m3 = identity(4);
    m3.m[2][2] = 5;
    print_matrix(m3);

    t_matrix m4 = mult_matrices(m3, m2);
    print_matrix(m4);
}
