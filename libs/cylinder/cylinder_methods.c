#include "cylinder.h"

void print_cylinder( void *s)
{
    const t_cylinder *cylinder;
    
    cylinder = (t_cylinder *)s;
    if (!cylinder)
        return ;
    printf("Cylinder %d\n", cylinder->shape.id);
    printf("Origin: ");
    print_tuple((const t_tuple *)(cylinder->o));
    printf("Radius: %f\n", cylinder->radius);
    printf("Transform:\n");
    print_matrix(cylinder->shape.tr);
    printf("Material:\n");
    print_material(*(cylinder->shape.material));
}

void intersect_cylinder(void *s, const t_ray ray, t_intersection **_xs)
{
    t_cylinder *cyl;
    double a;
    double b;
    double c;
    double disc;
    double t0;
    double t1;

    cyl = (t_cylinder *)s;   
    *_xs =  NULL;
    a = pow(ray.di->x, 2) + pow(ray.di->z, 2);
    if (equal(a, 0))
        return ;
    b = 2 * ray.o->x * ray.di->x + (2 * ray.o->z * ray.di->z);
    c = pow(ray.o->x, 2) + pow(ray.o->z, 2) - 1;
    disc = pow(b, 2) - 4 * a * c;
    if (disc < 0)
        return ;
    t0 = (-b - sqrt(disc)) / (2 * a);
    t1 = (-b + sqrt(disc)) / (2 * a);
    if (t0 > t1)
    {
        double tmp = t0;
        t0 = t1;
        t1 = tmp;
    }
    double y0 = ray.o->y + (t0 * ray.di->y);
    t_intersection *i1 = NULL;
    if (cyl->min_y < y0 && y0 < cyl->max_y)
        i1 = xs(t0, CYLINDER, s);
    double y1 = ray.o->y + (t1 * ray.di->y);
    t_intersection *i2 = NULL;
    if (cyl->min_y < y1 && y1 < cyl->max_y)
        i2 = xs(t1, CYLINDER, s);
    *_xs = merge_sorted(&i1, &i2);
}

void cylinder_normal_at(void *s, const t_tuple object_point, t_tuple **normal)
{
    t_cylinder *cyl;

    cyl = (t_cylinder *)s;
    if (!cyl)
        return ;
    *normal = vector(object_point.x, 0, object_point.z);
    if (!*normal)
    {
        printf("Error: cylinder_normal_at: operation failed.\n");
        *normal = NULL;
    }
}
