/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:20:24 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix *identity(const unsigned int size)
{
    t_matrix *id;
    unsigned int i;
    unsigned int j;

    id = matrix(size, size);
    if (!id)
        return NULL;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (i == j)
                id->m[i][j] = 1;
            j++;
        }
        i++;
    }
    return id;
}

t_matrix *translation(double x, double y, double z)
{
    t_matrix *translation;

    translation = identity(4);
    if (!translation)
        return (NULL);
    translation->m[0][3] = x;
    translation->m[1][3] = y;
    translation->m[2][3] = z;
    return translation;
}

t_matrix *scaling(double x, double y, double z)
{
    t_matrix *scaling;

    scaling = identity(4);
    if (!scaling)
        return (NULL);
    scaling->m[0][0] = x;
    scaling->m[1][1] = y;
    scaling->m[2][2] = z;

    return scaling;
}

t_matrix *rotation_x(double rad)
{
    t_matrix *rotation;

    rotation = identity(4);
    if (!rotation)
        return NULL;
    rotation->m[1][1] = cos(rad);
    rotation->m[1][2] = -sin(rad);
    rotation->m[2][1] = sin(rad);
    rotation->m[2][2] = cos(rad);

    return rotation;
}

t_matrix *rotation_y(double rad)
{
    t_matrix *rotation;

    rotation = identity(4);
    if (!rotation)
        return NULL;
    rotation->m[0][0] = cos(rad);
    rotation->m[0][2] = sin(rad);
    rotation->m[2][0] = -sin(rad);
    rotation->m[2][2] = cos(rad);

    return rotation;
}

t_matrix *rotation_z(double rad)
{
    t_matrix *rotation;

    rotation = identity(4);
    if (!rotation)
        return NULL;
    rotation->m[0][0] = cos(rad);
    rotation->m[0][1] = -sin(rad);
    rotation->m[1][0] = sin(rad);
    rotation->m[1][1] = cos(rad);

    return rotation;
}

t_matrix *shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
    t_matrix *shearing;

    shearing = identity(4);
    if (!shearing)
        return NULL;
    shearing->m[0][1] = xy;
    shearing->m[0][2] = xz;
    shearing->m[1][0] = yx;
    shearing->m[1][2] = yz;
    shearing->m[2][0] = zx;
    shearing->m[2][1] = zy;

    return shearing;
}

t_matrix *chain_tfs(t_matrix *initial, ...)
{
    va_list args;
    t_matrix *next_transform;
    t_matrix *result;
    t_matrix *temp;

    va_start(args, initial);
    result = initial;
    while (1)
    {
        next_transform = (t_matrix *)va_arg(args, t_matrix *);
        if (next_transform == NULL)
            break;
        temp = mult_matrices(*result, *next_transform);
        free_matrix(&result);
        free_matrix(&next_transform);
        result = temp;
    }
    va_end(args);
    return result;
}

t_matrix *rotation_matrix(double angle, double x, double y, double z)
{
    t_matrix *r;
    double cosTheta;
    double sinTheta;
    double oneMinusCos;
    double length;

    r = identity(4);
    if (!r)
        return NULL;
    cosTheta = cos(angle);
    sinTheta = sin(angle);
    oneMinusCos = 1 - cosTheta;
    length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;

    r->m[0][0] = (x * x * oneMinusCos) + cosTheta;
    r->m[0][1] = (x * y * oneMinusCos) - (z * sinTheta);
    r->m[0][2] = (x * z * oneMinusCos) + (y * sinTheta);
    r->m[1][0] = (y * x * oneMinusCos) + (z * sinTheta);
    r->m[1][1] = (y * y * oneMinusCos) + cosTheta;
    r->m[1][2] = (y * z * oneMinusCos) - (x * sinTheta);
    r->m[2][0] = (z * x * oneMinusCos) - (y * sinTheta);
    r->m[2][1] = (z * y * oneMinusCos) + (x * sinTheta);
    r->m[2][2] = (z * z * oneMinusCos) + cosTheta;

    return r;
}

void transform(void *elem, t_matrix *transformation)
{
    t_tf *tf;

    if (!elem || !transformation)
    {
        printf("Error: transform: couldn't perform transformation: null arguments.\n");
        free_matrix(&transformation);
        return;
    }
    tf = (t_tf *)elem;
    tf->transform(elem, transformation);
}