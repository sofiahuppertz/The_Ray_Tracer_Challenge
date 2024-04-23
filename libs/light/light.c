#include "light.h"

// Point light assigns the intensity and position to the light, it does not create new copies of the parameters.
t_point_light *point_light(t_color *intensity, t_tuple *position)
{
    t_point_light *light;

    if (!intensity || !position)
    {
        printf("Error: point_light: NULL parameter.\n");
        return (NULL);
    }
    light = (t_point_light *)calloc(1, sizeof(t_point_light));
    if (!light)
    {
        printf("Error: point_light: unable to allocate memory.\n");
        return (NULL);
    }
    light->intensity = intensity;
    light->position = position;
    return light;
}


void free_point_light(t_point_light **light)
{
    if (!light || !*light)
        return;
    free((*light)->intensity);
    free((*light)->position);
    free(*light);
    *light = NULL;
}


void print_point_light(const t_point_light light)
{
    printf("Intensity: ");
    print_color((const t_color)(*light.intensity));
    printf("Position: ");
    print_tuple((const t_tuple*)light.position);
}













