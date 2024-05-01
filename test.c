#include "libs/librt.h"


int main(void)
{
	t_cone *con;

	con = cone();
	set_bounds(&con->c, -0.5, 0.5);
	set_closed(&con->c, 1);

	t_tuple *p;
	t_tuple *n;

	p = point(0, 0, 0);
	cyl_normal_at(&con->c, *p, &n);
	print_tuple(n);
	free(p);
	free(n);

	p = point(1, 1, 1);
	cyl_normal_at(&con->c, *p, &n);
	print_tuple(n);
	free(p);
	free(n);

	p = point(-1, -1, 0);
	cyl_normal_at(&con->c, *p, &n);
	print_tuple(n);
	free(p);
	free(n);

	
}
