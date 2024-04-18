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

t_material *default_material( void )
{
    t_material *material;

    material = (t_material *)calloc(1, sizeof(t_material));
    if (!material)
    {
        printf("Error: default_material: unable to allocate memory.\n");
        return (NULL);
    }
    material->color = color(1, 1, 1);
    if (!material->color)
    {
        printf("Error: default_material: unable to allocate memory.\n");
        free(material);
        return (NULL);
    }
    material->ambient = 0.1;
    material->diffuse = 0.9;
    material->specular = 0.9;
    material->shininess = 200.0;
    return material;
}


void free_material(t_material **material)
{
    if (!material || !*material)
        return;
    free((*material)->color);
    free(*material);
    *material = NULL;
}

t_material *material(t_color *color, double ambient, double diffuse, double specular, double shininess)
{
    t_material *material;

    if (!color)
    {
        printf("Error: material: NULL parameter.\n");
        return (NULL);
    }
    material = (t_material *)calloc(1, sizeof(t_material));
    if (!material)
    {
        printf("Error: material: unable to allocate memory.\n");
        return (NULL);
    }
    material->color = color;
    material->ambient = ambient;
    material->diffuse = diffuse;
    material->specular = specular;
    material->shininess = shininess;
    return material;
}

t_material *materialcpy(const t_material material)
{
    t_material *cpy;

    cpy = (t_material *)calloc(1, sizeof(t_material));
    if (!cpy)
    {
        printf("Error: materialcpy: unable to allocate memory.\n");
        return (NULL);
    }
    cpy->color = colorcpy(*material.color);
    if (!cpy->color)
    {
        printf("Error: materialcpy: failed.\n");
        free(cpy);
        return (NULL);
    }
    cpy->ambient = material.ambient;
    cpy->diffuse = material.diffuse;
    cpy->specular = material.specular;
    cpy->shininess = material.shininess;
    return cpy;
}


void print_material(const t_material material)
{
    printf("Color: ");
    print_color((const t_color)(*material.color));
    printf("Ambient: %f\n", material.ambient);
    printf("Diffuse: %f\n", material.diffuse);
    printf("Specular: %f\n", material.specular);
    printf("Shininess: %f\n", material.shininess);
}


void set_material_color(t_material *material, t_color *color)
{
    if (!material || !color)
    {
        printf("Error: set_material_color: NULL parameter.\n");
        return;
    }
    free(material->color);
    material->color = color;
}
