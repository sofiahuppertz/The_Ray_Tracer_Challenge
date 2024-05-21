#include "parse.h"

int parse_ambiant_light(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (count_nb_elm(split, 3) == 1)
        return (1);
    if (check_range(split, p) == 1)
    {
        free_split(split);
        return (1);
    }
    if (check_rgb(split[2], p) == 1)
    {
        free_split(split);
        return (1);
    }
    make_ambient_light(ft_atof(split[1]), color(div_255(p->r), div_255(p->g), div_255(p->b)));
    free_split(split);
    return (0);
}

int parse_camera(t_parse *p, char *line)
{
    char    **split;
    int     i;

    i = -1;
    split = ft_split(line, ' ');
    if (count_nb_elm(split, 4) == 1)
        return (1);
    while (split[3][++i])
    {
        if (ft_isdigit(split[3][i]) == 0 && split[3][i] != 13)
        {
            free_split(split);
            return (1);
        }
    }
    if (vector_range(split, p) == 1 || check_xyz(p, split) == 1 ||
        ft_atoi(split[3]) < 0 || ft_atoi(split[3]) > 180)
    {
        free_split(split);
        return (1);
    }
    make_camera(point(p->x, p->y, p->z), point(p->vr_1,p->vr_2, p->vr_3), degrees_to_radians(ft_atoi(split[3])));
    free_split(split);
    return (0);
}

int parse_light(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (count_nb_elm(split, 4) == 1)
        return (1);
    if (check_xyz(p, split) == 1 || count_comma(split[1]) == 1 ||
        check_rgb(split[3], p) == 1)
    {
        free_split(split);
        return (1);
    }
    if (ft_atof(split[2]) < 0 || ft_atof(split[2]) > 1)
    {
        free_split(split);
        return (1);
    }
	make_light(point(p->x, p->y, p->z), ft_atof(split[2]), color(div_255(p->r), div_255(p->g), div_255(p->b)));
    free_split(split);
    return (0);
}

int parse_plan(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (count_nb_elm(split, 4) == 2)
    {
        free_split(split);
        return (1);
    }
    else if (count_nb_elm(split, 4) == 1)
    {
        if (check_extra(split, p) == 1)
            return (1);
        if (count_nb_elm(split, 4 + p->count) == 1)
        {
            free_split(split);
            return (1);
        }
    }
    if (parse_plan_utils(p, split) == 1)
        return (1);
    free_split(split);
    return (0);
}

int parse_sphere(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (count_nb_elm(split, 4) == 2)
    {
        free_split(split);
        return (1);
    }
    else if (count_nb_elm(split, 4) == 1)
    {
        if (check_extra(split, p) == 1 || count_nb_elm(split,
            4 + p->count) == 1)
        {
            free_split(split);
            return (1);
        }
    }
    if (parse_sphere_utils(p, split) == 1)
        return (1);
    free_split(split);
    return (0);
}
