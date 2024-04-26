#include "material.h"

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
    material->pattern = NULL;
    return material;
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
    material->pattern = NULL;
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
    cpy->pattern = NULL;
    if (material.pattern)
    {
        cpy->pattern = patterncpy(*material.pattern);
        if (!cpy->pattern)
        {
            printf("Error: materialcpy: patterncpy failed.\n");
            free_material(&cpy);
            return (NULL);
        }
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
    print_color(*material.color);
    if (material.pattern)
        print_pattern(*material.pattern);
    printf("Ambient: %f\n", material.ambient);
    printf("Diffuse: %f\n", material.diffuse);
    printf("Specular: %f\n", material.specular);
    printf("Shininess: %f\n", material.shininess);
}

void set_color(t_material *material, t_color *color)
{
    if (!material || !color)
    {
        printf("Error: set_color: NULL parameter.\n");
        return;
    }
    free(material->color);
    material->color = color;
}

void set_pattern(t_material *material, t_pattern *pattern)
{
    if (!material || !pattern)
    {
        printf("Error: set_pattern: NULL parameter.\n");
        return;
    }
    if (material->pattern)
        free_pattern(&material->pattern);
    material->pattern = pattern;
}

void remove_pattern(t_material *material)
{
    if (!material)
    {
        printf("Error: remove_pattern: NULL parameter.\n");
        return;
    }
    if (material->pattern)
        free_pattern(&material->pattern);
}

void free_material(t_material **material)
{
    if (!material || !*material)
        return;
    free((*material)->color);
    if ((*material)->pattern)
        free_pattern(&(*material)->pattern);
    free(*material);
    *material = NULL;
}