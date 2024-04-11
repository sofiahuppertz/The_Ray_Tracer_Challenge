#include "libs/declarations/tuple.h"
#include "libs/declarations/color.h"
#include "libs/declarations/matrix.h"
#include <stdio.h>


int main(void){

    t_tuple t = point(1, 0, 1);

    t_matrix *chained = chain_transformations(translation(10, 5, 7), scaling(5, 5, 5), rotation_x(degrees_to_radians(90)), NULL);
    print_matrix(*chained);

    t_matrix *tuple = tuple_to_matrix(t);
    t_matrix *final = mult_matrices(*chained, *tuple);
    print_matrix(*final);
    free_matrix(chained);
    free_matrix(tuple);
    free_matrix(final);
}
