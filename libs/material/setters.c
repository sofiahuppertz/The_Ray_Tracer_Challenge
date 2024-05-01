#include "material.h"

void set_ambient(t_material *material, double ambient)
{
    if (!material)
    {
        printf("Error: set_ambient: NULL parameter.\n");
        return;
    }
    if (ambient <= 0.0)
        material->ambient = 0.0;
    else
        material->ambient = ambient;
}

void set_ambient_color(t_material *material, t_color *color)
{
    if (!material || !color)
    {
        printf("Error: set_ambient_color: NULL parameter.\n");
        return;
    }
    if (material->ambient_color)
        free(material->ambient_color);
    material->ambient_color = color;
}

void set_diffuse(t_material *material, double diffuse)
{
    if (!material)
    {
        printf("Error: set_diffuse: NULL parameter.\n");
        return;
    }
    if (diffuse <= 0.0)
        material->diffuse = 0.0;
    else
        material->diffuse = diffuse;
}

void set_specular(t_material *material, double specular)
{
    if (!material)
    {
        printf("Error: set_specular: NULL parameter.\n");
        return;
    }
    if (specular <= 0.0)
        material->specular = 0.0;
    else
        material->specular = specular;
}

void set_shininess(t_material *material, double shininess)
{
    if (!material)
    {
        printf("Error: set_shininess: NULL parameter.\n");
        return;
    }
    if (shininess <= 10.0)
        material->shininess = 10.0;
    else if (shininess >= 200.0)
        material->shininess = 200.0;
    else
        material->shininess = shininess;
}


void set_reflective(t_material *material, double reflective)
{
    if (!material)
    {
        printf("Error: set_reflective: NULL parameter.\n");
        return;
    }
    if (reflective <= 0.0)
        material->reflective = 0.0;
    if (reflective >= 1.0)
        material->reflective = 1.0;
    else
        material->reflective = reflective;
}

void set_transparency(t_material *material, double transparency)
{
    if (!material)
    {
        printf("Error: set_transparency: NULL parameter.\n");
        return;
    }
    if (transparency <= 0.0)
        material->transparency = 0.0;
    if (transparency >= 1.0)
        material->transparency = 1.0;
    else
        material->transparency = transparency;
}

void set_refrac_index(t_material *material, double refrac_index)
{
    if (!material)
    {
        printf("Error: set_refrac_index: NULL parameter.\n");
        return;
    }
    material->refrac_index = refrac_index;
}