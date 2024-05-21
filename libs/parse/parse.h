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
   double     r;
   double     g;
   double     b;
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

/* utils 2 */
char    *rm_space_malloc(char *str, char *new);
char    *rm_space(char *str);
char    *rewrite_extra_alpha_malloc(char *str, char *new);
char    *rewrite_extra_alpha(char *str);
double	ft_atof(char *str);

/* scene element */
int     parse_ambiant_light(t_parse *p, char *line);
int     parse_camera(t_parse *p, char *line);
int     parse_light(t_parse *p, char *line);
int     parse_plan(t_parse *p, char *line);
int     parse_sphere(t_parse *p, char *line);

/* scene element 2 */
int     parse_cylinder_utils(t_parse *p, char **split);
int     parse_cylinder(t_parse *p, char *line);
int     parse_cone(t_parse *p, char *line);
int     parse_plan_utils(t_parse *p, char **split);
int     parse_sphere_utils(t_parse *p, char **split);

/* syntax check */
int     check_rgb(char *split, t_parse *p);
int     check_range(char **split, t_parse *p);
int     vector_range(char **split, t_parse *p);
int     check_xyz(t_parse *p, char **split);
int     check_diameter(char *diameter, t_parse *p);

/* syntax check utils */
int     check_rgb_syntax(char **color_tab, char *color_str);
int     check_vector_syntax_utils(char **split_tmp, char *tmp, int j);
int     check_vector_syntax(char **split_tmp, char *split_tmp_str, char *tmp);
int     check_xyz_syntax(char **split, char **split_tmp, char *split_tmp_str);

/* extra */
int     parse_checker(char **arg, t_parse *p);
int     parse_stripe(char **arg, t_parse *p);
int     parse_transparency(char **arg, t_parse *p);
int     parse_refraction(char **arg, t_parse *p);
int     parse_reflection(char **arg, t_parse *p);

/* extra utils */
int     checker_error(char **arg, t_parse *p, int i);
int     stripe_error(char **arg, t_parse *p, int i);
int     transparency_error(char **arg, char *tmp, int i);
int     refraction_error(char **arg, char *tmp, int i);
int     reflection_error(char **arg, char *tmp, int i);

/* check extra */
void    params_order(t_attributes *extra, t_parse *p);
int     check_third(char **split, char *tmp, t_parse *p);
int     check_sec(char **split, char *tmp, t_parse *p);
int     check_first(char **split, char *tmp, t_parse *p);
int     check_extra(char **split, t_parse *p);

#endif
