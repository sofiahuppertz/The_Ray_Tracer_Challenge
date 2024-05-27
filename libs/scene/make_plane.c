#include "scene.h"

static void setup_plane(t_plane *pl, t_make_plane p, t_matrix *rotate, t_matrix *translate) 
{    
    t_scene *_scene;
    
    _scene = scene();
    set_material(&pl->shape, materialcpy(*_scene->material));
    set_pattern(pl->shape.material, solid(p.color));
    transform(&pl->shape, chain_tfs(translate, rotate, NULL));
}

void make_plane(t_make_plane p, t_attributes *attributes, ...) {
    t_scene *_scene;
    t_plane *pl;
    t_matrix *rotate;
    t_matrix *translate;
    va_list extras;

    _scene = scene();
    if (!_scene || !p.point || !p.normal || !p.color)
        return;
    pl = plane();
    if (!pl)
        return;
    rotate = find_rotation_matrix(*p.normal);
    translate = translation(p.point->x, p.point->y, p.point->z);
    setup_plane(pl, p, rotate, translate);
    if (attributes) {
        va_start(extras, attributes);
        set_extras(&pl->shape, attributes, extras);
        va_end(extras);
    }
    set_shape(_scene->world, (t_shape *)&pl->shape);
    free_tuples(&p.normal, &p.point, NULL);
}