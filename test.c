#include "libs/librt.h"


int main(void)
{
	t_cylinder *cyl = cylinder();
	set_bounds(cyl, 1, 2);
	set_closed(cyl, 1);

	t_ray *r1 = ray(point(0, 3, 0), vector(0, -1, 0));
	t_ray *r2 = ray(point(0, 3, -2), vector(0, -1, 2));
	t_ray *r3 = ray(point(0, 4, -2), vector(0, -1, 1));
	t_ray *r4 = ray(point(0, 0, -2), vector(0, 1, 2));
	t_ray *r5 = ray(point(0, -1, -2), vector(0, 1, 1));

	t_intersection *_xs = NULL;
	intersect_cylinder(cyl, *r1, &_xs);
	printf("Intersections: %d\n", count_intersections(_xs));
	free_intersections(&_xs);

	intersect_cylinder(cyl, *r2, &_xs);
	printf("Intersections: %d\n", count_intersections(_xs));
	free_intersections(&_xs);

	intersect_cylinder(cyl, *r3, &_xs);
	printf("Intersections: %d\n", count_intersections(_xs));
	free_intersections(&_xs);

	intersect_cylinder(cyl, *r4, &_xs);
	printf("Intersections: %d\n", count_intersections(_xs));
	free_intersections(&_xs);

	intersect_cylinder(cyl, *r5, &_xs);
	printf("Intersections: %d\n", count_intersections(_xs));
	free_intersections(&_xs);

	free_cylinder(cyl);
	free_ray(&r1);
	free_ray(&r2);
	free_ray(&r3);
	free_ray(&r4);
	free_ray(&r5);

	return (0);
}
