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
    char    **color;
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

/* parse */
int identify_2(t_parse *p, char *line);
int identify(t_parse *p, char *line);
int         check_file_rt(int fd);
int         check_cmd_line(int ac, char **av);

/* utils */
void    free_split(char **split);
int    parsing_error(int tmp, int fd);
int count_comma(char *line);
double	ft_atof(char *str);

/* scene element */
int ambiant_light(t_parse *p, char *line);
int camera(t_parse *p, char *line);
int light(t_parse *p, char *line);
int plan(t_parse *p, char *line);
int sphere(t_parse *p, char *line);
int cylinder(t_parse *p, char *line);

/* syntax check */
int check_rgb(char *split, t_parse *p);
int check_range(char **split, t_parse *p);
int vector_range(char **split);
int check_xyz(t_parse *p, char **split);
int check_diameter(char *diameter);

#endif
