/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:07 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:08 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern *solid(t_color *a)
{
    t_pattern *solid;

    solid = (t_pattern *)calloc(1, sizeof(t_pattern));
    if (!solid)
    {
        printf("Error: solid calloc failed.\n");
    }
    pattern(a, colorcpy(*a), solid);
    solid->local_pattern = solid_at;
    return solid;
}

t_color *solid_at(void *pattern, const t_tuple point)
{
    t_pattern *solid;

    (void)point;
    solid = (t_pattern *)pattern;
    return colorcpy(*solid->a);
}