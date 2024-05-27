/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:16:02 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 16:17:42 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	free_matrices(t_matrix *initial, ...)
{
	va_list		ap;
	t_matrix	*m;

	va_start(ap, initial);
	m = initial;
	while (m)
	{
		free_matrix(&m);
		m = va_arg(ap, t_matrix *);
		if (!m)
			break ;
	}
	va_end(ap);
}
