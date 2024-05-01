#include "scene.h"

t_scene *scene( void )
{
    t_scene *scene;

    scene = (t_scene *)calloc(1, sizeof(t_scene));
    if (!scene)
    {
        printf("Error: Calloc failed in scene\n");
        return (NULL);
    }
    scene->material = default_material();
    scene->world = empty_world();
    return (scene);
}