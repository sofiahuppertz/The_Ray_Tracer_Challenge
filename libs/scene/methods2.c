#include "scene.h"

void make_cone(t_tuple *c, t_tuple *axis, double unit_d, double height, t_color *color)
{
    t_scene *_scene;
    t_matrix *rotate;
    t_cone *co;
    double radius;

    _scene = scene();
    if (!_scene || !c || !axis || !color)
    {
        printf("Error: make_cone: invalid arguments.\n");
        return;
    }
    co = cone();
    if (!co)
        return;
    set_material(&co->c.shape, materialcpy(*_scene->material));
    set_bounds(&co->c, -height, 0);
    set_closed(&co->c, 1);
    rotate = find_rotation_matrix(*axis);
    radius = unit_d / 2.0;
    set_pattern(co->c.shape.material, solid(color));
    transform(&co->c.shape, chain_tfs(translation(c->x, c->y, c->z), rotate, scaling(radius, 1, radius), translation(0, height / 2.0, 0), NULL));
    set_shape(_scene->world, (t_shape *)&co->c);
    free_tuples(&c, &axis, NULL);
}