/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:49 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:48:07 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	*patterncpy(t_pattern p)
{
	t_pattern	*new;

	new = NULL;
	new = calloc(1, sizeof(t_pattern));
	if (!new)
	{
		printf("Error: stripe_pattern : calloc failed.\n");
		return (NULL);
	}
	pattern(colorcpy(*p.a), colorcpy(*p.b), new);
	new->local_pattern = p.local_pattern;
	transform((void *)new, matrixcpy(*p.tr));
	return (new);
}

void	add_pattern(t_pattern **list, t_pattern *pattern)
{
	t_pattern	*curr;

	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = pattern;
}

void	print_pattern(const t_pattern pattern)
{
	printf("Pattern:\n");
	printf("Color A: ");
	print_color(*pattern.a);
	printf("Color B: ");
	print_color(*pattern.b);
}

void	set_pattern_tr(void *s, t_matrix *transformation)
{
	t_pattern	*p;

	p = (t_pattern *)s;
	if (!p || !transformation)
	{
		printf("Error: set_pattern_tr: NULL pointer.\n");
		return ;
	}
	if (p->tr)
		free_matrix(&p->tr);
	p->tr = transformation;
}
