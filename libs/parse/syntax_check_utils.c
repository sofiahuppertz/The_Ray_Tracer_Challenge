/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:06 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 11:09:06 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_rgb_syntax(char **color_tab, char *color_str)
{
	int	j;

	j = -1;
	if (ft_atof(color_str) < 0.0 || ft_atof(color_str) > 255.0)
	{
		free_split(color_tab);
		return (1);
	}
	while (color_str[++j])
	{
		if (color_str[j] == '.')
			++j;
		if (color_str[j] && color_str[j] != 13 && ft_isdigit(color_str[j]) == 0
			&& color_str[j] != 9)
		{
			free_split(color_tab);
			return (1);
		}
	}
	return (0);
}

int	check_vector_syntax_utils(char **split_tmp, char *tmp, int j)
{
	if (j == 0 && (tmp[j] == '+' || tmp[j] == '-'))
		j++;
	else if ((ft_isdigit(tmp[0]) != 0 || tmp[0] == '+'
			|| tmp[0] == '-') && tmp[j] == '.')
		j++;
	if (tmp[j] && ft_isdigit(tmp[j]) == 0 && tmp[j] != 9)
	{
		free_split(split_tmp);
		free(tmp);
		return (-1);
	}
	return (j);
}

int	check_vector_syntax(char **split_tmp, char *split_tmp_str, char *tmp)
{
	int	j;

	j = 0;
	if (ft_atof(split_tmp_str) < -1 || ft_atof(split_tmp_str) > 1)
	{
		free_split(split_tmp);
		return (1);
	}
	if (tmp)
	{
		while (tmp[j])
		{
			j = check_vector_syntax_utils(split_tmp, tmp, j);
			if (j == -1)
				return (1);
			if (!tmp[j])
				break ;
			j++;
		}
		free(tmp);
	}
	return (0);
}

int	check_xyz_syntax(char **split, char **split_tmp, char *split_tmp_str)
{
	int	j;

	j = -1;
	if (split_tmp_str[0] == '+' || split_tmp_str[0] == '-')
		j++;
	while (split_tmp_str[++j])
	{
		if ((ft_isdigit(split_tmp_str[0]) == 1 || split_tmp_str[0] == '+'
				|| split_tmp_str[0] == '-') && split_tmp_str[j] == '.')
			j++;
		if (count_comma(split[1]) == 1 || ft_isdigit(split_tmp_str[j]) == 0)
		{
			free_split(split_tmp);
			return (1);
		}
	}
	return (0);
}
