/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:40 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:42 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_attributes *new_attr(void)
{
    t_attributes *attr;

    attr = (t_attributes *)calloc(1, sizeof(t_attributes));
    if (!attr)
        return NULL;
    return attr;
}

static t_attributes *double_attr(void)
{
    t_attributes *attr;

    attr = new_attr();
    if (!attr)
        return (NULL);
    attr->key = (char *)calloc(4, sizeof(char));
    if (!attr->key)
    {
        free(attr);
        return (NULL);
    }
    attr->value = (double *)calloc(1, sizeof(double));
    if (!attr->value)
    {
        free(attr->key);
        free(attr);
        return (NULL);
    }
    return (attr);
}

static void add_to_material(t_material *material, t_attributes *attr)
{
    if (!material || !attr)
        return;
    if (!strcmp(attr->key, "checker") || !strcmp(attr->key, "stripe"))
    {
        set_pattern(material, (t_pattern *)attr->value);
        free(attr->key);
        return;
    }
    else if (!strcmp(attr->key, "rfl"))
        set_reflective(material, *(double *)attr->value);
    else if (!strcmp(attr->key, "rfr"))
    {
        set_refrac_index(material, *(double *)attr->value);
        set_diffuse(material, 1 - *(double *)attr->value);
    }
    else if (!strcmp(attr->key, "tsy"))
    {
        set_transparency(material, *(double *)attr->value);
        set_shininess(material, 300);
        set_specular(material, 0.9);
    }
    free(attr->key);
    free(attr->value);
}

void set_extras(t_shape *shape, t_attributes *first_extra, va_list extras)
{
    t_attributes *attr;
    t_material *material;

    if (!first_extra || !shape)
        return;
    material = shape->material;
    attr = first_extra;
    while (attr)
    {
        add_to_material(material, attr);
        free(attr);
        attr = va_arg(extras, t_attributes *);
        if (!attr)
            break;
    }
}

t_attributes *checker(t_color *a, t_color *b)
{
    t_attributes *attr;

    if (!a || !b)
        return (NULL);
    attr = new_attr();
    if (!attr)
        return (NULL);
    attr->key = (char *)calloc(8, sizeof(char));
    if (!attr->key)
        return (NULL);
    strcpy(attr->key, "checker");
    attr->value = checker_pattern(a, b);
    return (attr);
}

t_attributes *stripe(t_color *a, t_color *b, double width, double r_z)
{
    t_attributes *attr;

    if (!a || !b)
        return (NULL);
    attr = new_attr();
    if (!attr)
        return (NULL);
    attr->key = (char *)calloc(7, sizeof(char));
    if (!attr->key)
        return (NULL);
    strcpy(attr->key, "stripe");
    attr->value = stripe_pattern(a, b);
    transform(attr->value, chain_tfs(scaling(width, width, width), rotation_z(degrees_to_radians(r_z)), NULL));
    return (attr);
}

t_attributes *rfl(double reflectivity)
{
    t_attributes *attr;

    attr = double_attr();
    if (!attr)
    {
        printf("Error: rfl: failed.\n");
        return (NULL);
    }
    strcpy(attr->key, "rfl");
    *(double *)attr->value = reflectivity;
    return (attr);
}

t_attributes *rfr(double refractive_index)
{
    t_attributes *attr;

    attr = double_attr();
    if (!attr)
    {
        printf("Error: rfr: failed.\n");
        return (NULL);
    }
    strcpy(attr->key, "rfr");
    *(double *)attr->value = refractive_index;
    return (attr);
}

t_attributes *tsy(double transparency)
{
    t_attributes *attr;

    attr = double_attr();
    if (!attr)
    {
        printf("Error: try: failed.\n");
        return (NULL);
    }
    strcpy(attr->key, "tsy");
    *(double *)attr->value = transparency;
    return (attr);
}
