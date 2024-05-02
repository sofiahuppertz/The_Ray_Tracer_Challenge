#ifndef SCENE_H
#define SCENE_H

#include "../camera/camera.h"

#define HEIGHT 80
#define WIDTH 80

typedef struct s_scene
{
    t_material *material;
    t_camera *camera;
    t_world *world; 
    t_canvas *canvas;

} t_scene;

t_scene *scene( void );

void make_ambient_light(t_scene *scene, double ratio, t_color *color);
void make_camera(t_scene *scene, t_tuple *view_point, t_tuple *orientation, double field_of_view);
void make_light(t_scene *scene, t_tuple *position, double brightness, t_color *color);
void make_sphere(t_scene *scene, t_tuple *center, double diameter, t_color *color);
void make_plane(t_scene *scene, t_tuple *point, t_tuple *normal, t_color *color);
void make_cylinder(t_scene *scene, t_tuple *center, t_tuple *axis, double diameter, double height, t_color *color);
void make_cone(t_scene *scene, t_tuple *center, t_tuple *axis, double unit_d, double height, t_color *color);


# endif