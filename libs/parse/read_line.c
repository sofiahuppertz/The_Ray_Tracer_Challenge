/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:52 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 11:09:52 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_free_str(char **s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

static int	save_line(char **str, char **line)
{
	int		l;
	char	*tmp;

	l = 0;
	while ((*str)[l] != '\n' && (*str)[l] != '\0')
		l++;
	if ((*str)[l] == '\n')
	{
		*line = ft_substr(*str, 0, l);
		tmp = ft_strdup(&((*str)[l + 1]));
		ft_free_str(str);
		*str = tmp;
		if ((**str) == '\0')
			ft_free_str(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_free_str(str);
		*str = NULL;
		return (0);
	}
	return (1);
}

static int	filter(char **str, int fd, char **line, int r)
{
	if (r == 0 && !str[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (r < 0)
		return (-1);
	return (save_line(&str[fd], line));
}

void	ft_read_else(char **tmp, char **str, char **buff, int fd)
{
	*tmp = ft_strjoin(str[fd], *buff);
	free(str[fd]);
	str[fd] = *tmp;
}

int	read_line(int fd, char **line, int buffer_size)
{
	int			r;
	char		*tmp;
	static char	*str[256];
	char		*buff;

	if (fd < 0 || !line || fd > 256 || buffer_size <= 0)
		return (-1);
	buff = malloc(buffer_size + 1);
	if (!buff)
		return (-1);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, buffer_size);
		buff[r] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
			ft_read_else(&tmp, &(*str), &buff, fd);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buff);
	return (filter(str, fd, line, r));
}
