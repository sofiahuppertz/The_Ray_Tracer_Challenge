#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>

#define PI 3.14159265358979323846




int main(void)
{
	t_world *w;
	t_ray *r;
	t_tuple *origin;
	t_tuple *direction;

	w = default_world();
	origin = point(0, 0, -5);
	direction = vector(0, 0, 1);
	r = ray(*origin, *direction);

	t_intersection *xs = intersect_world(*w, *r);
	t_intersection *i = hit(&xs);
	t_comps *comps = prepare_computations(*i->next, *r);
	print_comps(comps);
	free_comps(&comps);
	free_intersections(&xs);
	free_ray(&r);
	free_world(&w);
}
