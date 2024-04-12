#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>


int main(void){

    //Ray tests

	t_tuple *origin = point(2,3,4);
	t_tuple *direction = vector(1, 0, 0);
	t_ray *r = ray(*origin, *direction);
	print_tuple((const t_tuple)(*r->di));
	t_tuple *p = position(*r, 0);
	print_tuple(*p);

	free_ray(r);
	free(origin);
	free(direction);
	free(p);


    return 0;

}
