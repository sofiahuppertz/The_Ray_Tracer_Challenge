#include "parse.h"

int ambiant_light(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
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
    free_split(split);
    return (0);
}

int camera(t_parse *p, char *line)
{
    char    **split;
    int     i;

    i = 0;
    split = ft_split(line, ' ');
    if (ft_atoi(split[3]) < 0 || ft_atoi(split[3]) > 180)
    {
        free_split(split);
        return (1);
    }
    while (split[3][i])
    {
        if (ft_isdigit(split[3][i]) == 0 && split[3][i] != 13)
        {
            free_split(split);
            return (1);
        }
        i++;
    }
    if (vector_range(split) == 1 || check_xyz(p, split) == 1)
    {
        free_split(split);
        return (1);
    }
    free_split(split);
    return (0);
}

int light(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (check_xyz(p, split) == 1 || count_comma(split[1]) == 1)
    {
        free_split(split);
        return (1);
    }
    if (ft_atof(split[2]) < 0 || ft_atof(split[2]) > 1)
    {
        free_split(split);
        return (1);
    }
    if (check_rgb(split[3], p) == 1)
    {
        free_split(split);
        return (1);
    }
    free_split(split);
    return (0);
}

int plan(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1 ||
        vector_range(split) == 1)
    {
        free_split(split);
        return (1);
    }
    free_split(split);
    return (0);
}

int sphere(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1 ||
        check_diameter(split[2]) == 1)
    {
        free_split(split);
        return (1);
    }
    free_split(split);
    return (0);
}

int cylinder(t_parse *p, char *line)
{
    char    **split_tmp;
    char    **split;
    int     i;

    i = 0;
    (void)p;
    split = ft_split(line, ' ');
    split_tmp = ft_split(split[2], ',');
    if (check_xyz(p, split) == 1 || check_diameter(split[3]) == 1 ||
        check_diameter(split[4]) == 1 || check_rgb(split[5], p) == 1)
    {
        free_split(split);
        free_split(split_tmp);
        return (1);
    }
    free_split(split);
    while (split_tmp[i])
    {
        if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1)
        {
            free_split(split_tmp);
            return (1);
        }
        i++;
    }
    free_split(split_tmp);
    return (0);
}
