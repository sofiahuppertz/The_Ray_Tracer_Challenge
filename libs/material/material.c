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
    set_ambient(material, 0.1);
    set_ambient_color(material, color(1, 1, 1));
    set_diffuse(material, 0.9);
    set_specular(material, 0.9);
    set_shininess(material, 200.0);
    set_reflective(material, 0.0);
    set_refrac_index(material, Air);
    set_pattern(material, solid(white()));

    return material;
}

t_material *material(t_pattern *pat, double ambient, double diffuse, double specular, double shininess)
{
    t_material *material;

    if (!pat)
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
    set_ambient(material, ambient);
    set_ambient_color(material, color(1, 1, 1));
    set_diffuse(material, diffuse);
    set_specular(material, specular);
    set_shininess(material, shininess);
    set_reflective(material, 0.0);
    set_transparency(material, 0.0);
    set_refrac_index(material, 1.0);
    set_pattern(material, pat);
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
    set_ambient_color(cpy, colorcpy(*material.ambient_color));
    set_ambient(cpy, material.ambient);
    set_diffuse(cpy, material.diffuse);
    set_specular(cpy, material.specular);
    set_shininess(cpy, material.shininess);
    set_reflective(cpy, material.reflective);
    set_transparency(cpy, material.transparency);
    set_refrac_index(cpy, material.refrac_index);
    return cpy;
}

void print_material(const t_material material)
{
    if (material.pattern)
        print_pattern(*material.pattern);
    printf("Ambient: %f\n", material.ambient);
    if (material.ambient_color)
        print_color(*material.ambient_color);
    printf("Diffuse: %f\n", material.diffuse);
    printf("Specular: %f\n", material.specular);
    printf("Shininess: %f\n", material.shininess);
    printf("Reflective: %f\n", material.reflective);
    printf("Transparency: %f\n", material.transparency);
    printf("Refractive index: %f\n", material.refrac_index);

}

//void set_color(t_material *material, t_color *color)
//{
//    if (!material || !color)
//    {
//        printf("Error: set_color: NULL parameter.\n");
//        return;
//    }
//    free(material->color);
//    material->color = color;
//}

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
    if ((*material)->pattern)
        free_pattern(&(*material)->pattern);
    free((*material)->ambient_color);
    free(*material);
    *material = NULL;
}