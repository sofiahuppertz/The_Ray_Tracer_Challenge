#include "scene.h"

void make_camera(t_tuple *view_point, t_tuple *orientation, double field_of_view)
{
    t_scene *_scene;
    t_camera *cam;
    t_matrix *vt;

    _scene = scene();
    if (!_scene || !view_point || !orientation)
    {
        printf("Error: make_camera: invalid arguments.\n");
        return;
    }
    cam = camera(HEIGHT, WIDTH, field_of_view);
    if (!cam)
        return;
    vt = view_transformation(view_point, orientation, vector(0, 1, 0));
    if (!vt)
    {
        free_camera(&cam);
        return;
    }
    transform(cam, vt);
    if (_scene->camera)
    {
        free_camera(&_scene->camera);
    }
    _scene->camera = cam;
}


void make_ambient_light(double ratio, t_color *color)
{
    t_scene *_scene;

    _scene = scene();
    if (!_scene || !color)
    {
        printf("Error: make_ambient_light: invalid arguments.\n");
        return;
    }
    if (!_scene->material)
    {
        _scene->material = default_material();
    }
    if (!_scene->material)
    {
        return;
    }
    set_ambient(_scene->material, ratio);
    set_ambient_color(_scene->material, color);
}


void make_light(t_tuple *position, double brightness, t_color *color)
{
    t_point_light *light;
    t_scene *_scene;

    _scene = scene();
    if (!_scene || !position || !color)
    {
        printf("Error: make_light: invalid arguments.\n");
        return;
    }
    light = point_light(color, position);
    if (!light)
        return;
    if (_scene->world->light)
    {
        free_point_light(&_scene->world->light);
    }
    _scene->world->light = light;
    if (!_scene->material)
    {
        _scene->material = default_material();
    }
    set_diffuse(_scene->material, brightness);
}

void make_sphere(t_tuple *center, double diameter, t_color *color)
{
    t_scene *_scene;
    t_sphere *sp;
    double radius;

    _scene = scene();
    if (!_scene || !center || !color)
    {
        printf("Error: make_sphere: invalid arguments.\n");
        return;
    }
    sp = sphere();
    if (!sp)
        return;
    set_material(&sp->shape, materialcpy(*_scene->material));
    set_pattern(sp->shape.material, solid(color));
    radius = diameter / 2.0;
    transform(&sp->shape, chain_tfs(translation(center->x, center->y, center->z), scaling(radius, radius, radius), NULL));
    set_shape(_scene->world, (t_shape *)&sp->shape);
}

void make_plane(t_tuple *point, t_tuple *normal, t_color *color)
{  
    t_scene *_scene; 
    t_plane *pl;
    t_matrix *rotate;
    t_matrix *translate;

    _scene = scene();
    if (!_scene || !point || !normal || !color)
    {
        printf("Error: make_plane: invalid arguments.\n");
        return;
    }
    pl = plane();
    if (!pl)
        return;
    set_material(&pl->shape, materialcpy(*_scene->material));
    set_pattern(pl->shape.material, solid(color));
    rotate = find_rotation_matrix(*normal);
    translate = translation(point->x, point->y, point->z);
    transform(&pl->shape, chain_tfs(translate, rotate, NULL));
    set_shape(_scene->world, (t_shape *)&pl->shape);
    free_tuples(&normal, &point, NULL);
}

void make_cylinder(t_tuple *center, t_tuple *axis, double diameter, double height, t_color *color)
{
    t_scene *_scene;
    t_cylinder *cy;
    t_matrix *rotate;
    double radius;

    _scene = scene();
    if (!_scene || !center || !axis || !color)
    {
        printf("Error: make_cylinder: invalid arguments.\n");
        return;
    }
    cy = cylinder();
    if (!cy)
        return;
    set_material(&cy->c.shape, materialcpy(*_scene->material));
    rotate = find_rotation_matrix(*axis);
    set_bounds(&cy->c, -height / 2.0, height / 2.0);
    set_closed(&cy->c, 1);
    radius = diameter / 2.0;
    transform(&cy->c.shape, chain_tfs(translation(center->x, center->y, center->z), rotate, scaling(radius, 1, radius), NULL));
    set_pattern(cy->c.shape.material, solid(color));
    set_shape(_scene->world, (t_shape *)&cy->c.shape);
    free_tuples(&axis, &center, NULL);
    
}