#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../scene/scene.h"

typedef struct s_parse
{
   int     A;
   int     C;
   int     L;
   double     x;
   double     y;
   double     z;
   double     diam;
   double     vr_1;
   double     vr_2;
   double     vr_3;
   double  chk_fc;
   double  chk_sc;
   double  str_fc;
   double  str_sc;
   int     r;
   int     g;
   int     b;
   int     chk;
   int     str;
   int     tsy;
   int     rfr;
   int     rfl;
   int     count;
   char    **color;
   char    **color_2;
   t_attributes *checker_attr;
   t_attributes *stripe_attr;
   t_attributes *transparency_attr;
   t_attributes *refraction_attr;
   t_attributes *reflection_attr;
   t_attributes *params[6];
}       t_parse;

// typedef struct s_parse
// {
//     int     A;
//     int     C;
//     int     L;
//     double     x;
//     double     y;
//     double     z;
//     double     diam;
//     double     vr_1;
//     double     vr_2;
//     double     vr_3;
//     int     r;
//     int     g;
//     int     b;
//     int     chk;
//     int     str;
//     int     tsy;
//     int     rfr;
//     int     rfl;
//     int     count;
//     char    **color;
    // double  chk_fc;
    // double  chk_sc;
    // double  str_fc;
    // double  str_sc;
//     double  str_width;
//     double  str_rot;
//     double  tsy_range;
//     double  rfr_range;
//     double  rfl_range;
//     double     ratio;
// }       t_parse;

/* read line */
int     read_line(int fd, char **line, int buffer_size);
void    ft_read_else(char **tmp, char **str, char **buff, int fd);
void    ft_free_str(char **s);

/* parse */
int     identify_2(t_parse *p, char *line);
int     identify(t_parse *p, char *line);
int     check_file_rt(int fd);
int     check_cmd_line(int ac, char **av);

/* utils */
void    free_split(char **split);
int     parsing_error(int tmp, int fd, t_parse *p);
int     count_comma(char *line);
int     count_nb_elm(char **line, int j);
int     check_id(char *line);
double	ft_atof(char *str);

/* scene element */
int     parse_ambiant_light(t_parse *p, char *line);
int     parse_camera(t_parse *p, char *line);
int     parse_light(t_parse *p, char *line);
int     parse_plan(t_parse *p, char *line);
int     parse_sphere(t_parse *p, char *line);
int     parse_cylinder(t_parse *p, char *line, char *n);
int     parse_cone(t_parse *p, char *line);

/* syntax check */
int     check_rgb(char *split, t_parse *p);
int     check_range(char **split, t_parse *p);
int     vector_range(char **split, t_parse *p);
int     check_xyz(t_parse *p, char **split);
int     check_diameter(char *diameter, t_parse *p);

/* extra */
int     parse_checker(char **arg, t_parse *p);
int     parse_stripe(char **arg, t_parse *p);
int     parse_transparency(char **arg, t_parse *p);
int     parse_refraction(char **arg, t_parse *p);
int     parse_reflection(char **arg, t_parse *p);

#endif
