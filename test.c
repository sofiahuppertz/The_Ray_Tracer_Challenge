#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>


int main(void){

    t_tuple *p1;
	t_tuple *p2;
	t_ray *r;
	t_sphere *s;
	t_intersection **i;

	p1 = point(0, 1, -5);
	p2 = vector(0, 0, 1);
	r = ray((const t_tuple)(*p1), (const t_tuple)(*p2));
	s = sphere();
	i = i_ray_sphere((*s), (*r));
	printf("solutions: %d\n", count_solutions(i));
	printf("Intersection ray-sphere: %f %f\n", i[0]->t, i[1]->t);
	printf("Intersection ray-sphere: %d %d\n", i[0]->object, i[1]->object);
	free(p1);
	free(p2);
	free_ray(&r);
	free_sphere(s);





    return 0;

}
