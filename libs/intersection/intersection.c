/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:34 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:06:12 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersection	*xs(const double t, const t_elem object, void *object_ptr)
{
	t_intersection	*i;

	i = (t_intersection *)calloc(1, sizeof(t_intersection));
	if (!i)
	{
		printf("Error: could not allocate memory for intersection\n");
		return (NULL);
	}
	i->t = t;
	i->object = object;
	i->object_ptr = object_ptr;
	i->next = NULL;
	return (i);
}

t_intersection	*merge_sorted(t_intersection **first, t_intersection **next)
{
	t_intersection	*result;

	result = NULL;
	if (*first == NULL)
		return (*next);
	if (*next == NULL)
		return (*first);
	if ((*first)->t <= (*next)->t)
	{
		result = *first;
		result->next = merge_sorted(&((*first)->next), next);
	}
	else
	{
		result = *next;
		result->next = merge_sorted(first, &((*next)->next));
	}
	return (result);
}

t_intersection	*intersections(t_intersection *initial, ...)
{
	t_intersection	*first;
	t_intersection	*next;
	va_list			args;

	va_start(args, initial);
	first = initial;
	if (first == NULL)
		printf("Error: first arg of intersections is NULL\n");
	else
	{
		while (1)
		{
			next = (t_intersection *)va_arg(args, t_intersection *);
			if (next == NULL)
				break ;
			first = merge_sorted(&first, &next);
		}
	}
	return (first);
}

int	count_intersections(t_intersection *xs)
{
	t_intersection	*temp;
	int				count;

	temp = xs;
	count = 0;
	if (temp)
	{
		while (temp)
		{
			temp = temp->next;
			count++;
		}
	}
	return (count);
}

t_intersection	*hit(t_intersection **xs)
{
	t_intersection	*hit;

	if (!xs || !(*xs))
		return (NULL);
	hit = *xs;
	if (hit->t < 0)
	{
		while (hit)
		{
			hit = hit->next;
			if (hit && hit->t >= 0)
				return (hit);
		}
		return (NULL);
	}
	else
		return (hit);
}
