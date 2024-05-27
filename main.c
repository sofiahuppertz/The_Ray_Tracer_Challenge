/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:35 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 17:10:26 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/librt.h"

int	check_map(int ac, char **av)
{
	int		fd;

	if (check_cmd_line(ac, av) == 1)
		return (1);
	fd = open(av[ac - 1], O_RDONLY);
	if (fd == -1)
	{
		close_window(NULL);
		perror("fd");
		close(fd);
		return (1);
	}
	if (check_file_rt(fd) == 1)
	{
		close_window(NULL);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	*_scene;

	_scene = scene();
	if (check_map(ac, av) == 1)
		return (1);
	_scene->canvas = render(_scene->camera, _scene->world);
	set_events_and_display(_scene->canvas);
	return (0);
}
