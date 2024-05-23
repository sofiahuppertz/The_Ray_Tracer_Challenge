/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:58:04 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:58:36 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

void	tupletype(t_tuple *a)
{
	if (a->w == 1.0)
		a->tf.type = POINT;
	else if (a->w == 0.0)
		a->tf.type = VECTOR;
	else
		a->tf.type = IDK;
	if (a->tf.type == IDK)
		print_tuple(a);
}

void	free_tuples(t_tuple **initial, ...)
{
	va_list	args;
	t_tuple	**t;

	va_start(args, initial);
	t = initial;
	while (t)
	{
		free(*t);
		t = NULL;
		t = (t_tuple **)va_arg(args, t_tuple **);
		if (!t || !*t)
			break ;
	}
	va_end(args);
}
