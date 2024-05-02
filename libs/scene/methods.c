#include "scene.h"

void make_camera(t_scene *scene, t_tuple *view_point, t_tuple *orientation, double field_of_view)
{
    t_camera *cam;
    t_matrix *vt;

    if (!scene || !view_point || !orientation)
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
    if (scene->camera)
    {
        free_camera(&scene->camera);
    }
    scene->camera = cam;
}


void make_ambient_light(t_scene *scene, double ratio, t_color *color)
{
    if (!scene || !color)
    {
        printf("Error: make_ambient_light: invalid arguments.\n");
        return;
    }
    if (!scene->material)
    {
        scene->material = default_material();
    }
    if (!scene->material)
    {
        return;
    }
    set_ambient(scene->material, ratio);
    set_ambient_color(scene->material, color);
}


void make_light(t_scene *scene, t_tuple *position, double brightness, t_color *color)
{
    t_point_light *light;

    if (!scene || !position || !color)
    {
        printf("Error: make_light: invalid arguments.\n");
        return;
    }
    light = point_light(color, position);
    if (!light)
        return;
    if (scene->world->light)
    {
        free_point_light(&scene->world->light);
    }
    scene->world->light = light;
    if (!scene->material)
    {
        scene->material = default_material();
    }
    set_diffuse(scene->material, brightness);
}

void make_sphere(t_scene *scene, t_tuple *center, double diameter, t_color *color)
{
    t_sphere *sp;
    double radius;

    if (!scene || !center || !color)
    {
        printf("Error: make_sphere: invalid arguments.\n");
        return;
    }
    sp = sphere();
    if (!sp)
        return;
    set_material(&sp->shape, materialcpy(*scene->material));
    set_pattern(sp->shape.material, solid(color));
    radius = diameter / 2.0;
    transform(&sp->shape, chain_tfs(translation(center->x, center->y, center->z), scaling(radius, radius, radius), NULL));
    set_shape(scene->world, (t_shape *)&sp->shape);
}

void make_plane(t_scene *scene, t_tuple *point, t_tuple *normal, t_color *color)
{   
    t_plane *pl;
    t_matrix *rotate;
    t_matrix *translate;

    if (!scene || !point || !normal || !color)
    {
        printf("Error: make_plane: invalid arguments.\n");
        return;
    }
    pl = plane();
    if (!pl)
        return;
    print_tuple(normal);
    set_material(&pl->shape, materialcpy(*scene->material));
    set_pattern(pl->shape.material, solid(color));
    rotate = find_rotation_matrix(*normal);
    translate = translation(point->x, point->y, point->z);
    transform(&pl->shape, chain_tfs(translate, rotate, NULL));
    set_shape(scene->world, (t_shape *)&pl->shape);
    free_tuples(&normal, &point, NULL);
}

void make_cylinder(t_scene *scene, t_tuple *center, t_tuple *axis, double diameter, double height, t_color *color)
{
    t_cylinder *cy;
    t_matrix *rotate;
    double radius;

    if (!scene || !center || !axis || !color)
    {
        printf("Error: make_cylinder: invalid arguments.\n");
        return;
    }
    cy = cylinder();
    if (!cy)
        return;
    set_material(&cy->c.shape, materialcpy(*scene->material));
    rotate = find_rotation_matrix(*axis);
    set_bounds(&cy->c, -height / 2.0, height / 2.0);
    set_closed(&cy->c, 1);
    radius = diameter / 2.0;
    transform(&cy->c.shape, chain_tfs(translation(center->x, center->y, center->z), rotate, scaling(radius, 1, radius), NULL));
    set_pattern(cy->c.shape.material, solid(color));
    set_shape(scene->world, (t_shape *)&cy->c.shape);
    free_tuples(&axis, &center, NULL);
    
}