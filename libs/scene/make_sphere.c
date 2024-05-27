#include "scene.h"

static void setup_sphere(t_sphere *sp, t_make_sphere s, double radius) 
{
    t_scene *_scene;

    _scene = scene();
    set_material(&sp->shape, materialcpy(*_scene->material));
    set_pattern(sp->shape.material, solid(s.color));
    transform(&sp->shape, chain_tfs(translation(s.center->x, s.center->y,
                s.center->z), scaling(radius, radius, radius), NULL));
}

void make_sphere(t_make_sphere s, t_attributes *attributes, ...) 
{
    t_scene *_scene;
    t_sphere *sp;
    double radius;
    va_list extras;

    _scene = scene();
    if (!_scene || !s.center || !s.color)
        return;
    sp = sphere();
    if (!sp)
        return;
    radius = s.diameter / 2.0;
    setup_sphere(sp, s, radius);
    if (attributes) 
    {
        va_start(extras, attributes);
        set_extras(&sp->shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&sp->shape);
    free(s.center);
}