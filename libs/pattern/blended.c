/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blended.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:39 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 15:42:00 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

void	while_loop(t_pattern *curr, const t_tuple point, t_color *res,
	t_color *temp)
{
	t_tuple		*object_p;
	t_color		*next;

	curr = curr->next;
	while (curr)
	{
		object_p = tuplecpy(point);
		transform((void *)object_p, inverse(*curr->tr));
		next = curr->local_pattern(curr, *object_p);
		free(object_p);
		if (!res)
			res = colorcpy(*next);
		else
		{
			temp = res;
			res = average_colors(*temp, *next);
			free(temp);
		}
		free(next);
		curr = curr->next;
	}
}

t_color	*blended_at(void *pattern, const t_tuple point)
{
	t_pattern	*curr;
	t_color		*res;
	t_color		*temp;

	res = NULL;
	temp = NULL;
	curr = (t_pattern *)pattern;
	if (!curr || !curr->next)
	{
		printf("Error: blended_at called with no patterns.\n");
		return (NULL);
	}
	while_loop(curr, point, res, temp);
	return (res);
}

t_pattern	*blended(t_pattern *patterns)
{
	t_pattern	*blended;

	blended = (t_pattern *)calloc(1, sizeof(t_pattern));
	if (!blended)
	{
		printf("Error: blended calloc failed.\n");
	}
	pattern(NULL, NULL, blended);
	blended->local_pattern = blended_at;
	blended->next = patterns;
	return (blended);
}
