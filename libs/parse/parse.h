#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_parse
{
    char    id;
    int     x;
    int     y;
    int     z;
    char    *color;
    int     rgb;
    double     ratio;
    int     drct;
    int     hight;
    int     diameter;
}       t_parse;

/* read line */
int	        read_line(int fd, char **line, int buffer_size);
void 	    ft_read_else(char **tmp, char **str, char **buff, int fd);
void	    ft_free_str(char **s);
// static int	filter(char **str, int fd, char **line, int r);
// static int	save_line(char **str, char **line);

/* parse */
int         check_file_rt(int fd);
int         check_cmd_line(int ac, char **av);

/* utils */
double custom_atof(const char *str);

#endif