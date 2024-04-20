#include "sphere.h"

t_sphere *sphere( void )
{
    t_sphere *s = NULL;
    static int sp_id = 0;
    
    s = (t_sphere *)calloc(sizeof(t_sphere), 1);
    if (!s)
        return NULL;
    s->o = point(0, 0, 0);
    if (!s->o)
    {
        free(s);
        return NULL;
    }
    s->radius = 1;
    s->id = sp_id++;
    s->tr = identity(4);
    if (!s->tr)
    {
        free(s->o);
        free(s);
        return NULL;
    }
    s->material = default_material();
    s->next = NULL;
    s->tf.type = SPHERE;
    s->tf.transform  = transform_sphere;
    return s;
}


void print_sphere( const t_sphere *s )
{
    printf("Sphere %d\n", s->id);
    printf("Origin: ");
    print_tuple((const t_tuple *)(s->o));
    printf("Radius: %f\n", s->radius);
    printf("Transform:\n");
    print_matrix((const t_matrix *)(s->tr));
    printf("Material:\n");
    print_material((const t_material)*(s->material));
}

void free_sphere(t_sphere **s)
{
    t_sphere *ptr;
    t_sphere *next;

    ptr = *s;
    while (ptr != NULL)
    {
        next = ptr->next; 
        free(ptr->o);
        ptr->o = NULL;
        free_matrix(&(ptr->tr));
        free_material(&(ptr->material));
        free(ptr);
        ptr = next; 
    }
    *s = NULL;
}
void transform_sphere(void *sphere, t_matrix *transformation)
{
    t_sphere *s;

    s = (t_sphere *)sphere;
    if (s->tr)
        free_matrix(&s->tr);
    s->tr = transformation;
}

t_tuple *normal_at(const t_sphere s, const t_tuple world_point)
{
    t_tuple *object_point;
    t_tuple *normal;
    t_matrix *t;

    object_point = tuplecpy(world_point);
    set_transform(POINT, object_point, inverse(*s.tr));
    normal = sub_tuple((const t_tuple)(*object_point), (const t_tuple)(*s.o));
    free(object_point);
    if (!normal)
    {
        printf("Error: normal_at: operation failed.\n");
        return NULL;
    }
    t = inverse(*s.tr);
    transpose(&t);
    transform_tuple(normal, t);
    normal->w = 0;
    norm(normal);
    return normal;
}

void set_material(t_sphere *s, t_material *m)
{
    if (s->material)
        free_material(&(s->material));
    s->material = m;
}