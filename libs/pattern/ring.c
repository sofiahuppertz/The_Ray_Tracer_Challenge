/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:02 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern *ring(t_color *a, t_color *b)
{
    t_pattern *ring;

    ring = (t_pattern *)calloc(1, sizeof(t_pattern));
    if (!ring)
    {
        printf("Error: ring calloc failed.\n");
    }
    pattern(a, b, ring);
    ring->local_pattern = ring_at;
    return ring;
}

t_color *ring_at(void *pattern, const t_tuple point)
{
    t_pattern *ring;
    double variable;

    ring = (t_pattern *)pattern;
    variable = sqrt(pow(point.x, 2) + pow(point.z, 2));
    if ((int)floor(variable) % 2 == 0)
        return colorcpy(*ring->a);
    return colorcpy(*ring->b);
}