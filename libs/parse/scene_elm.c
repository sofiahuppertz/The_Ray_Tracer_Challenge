#include "parse.h"

int ambiant_light(t_parse *p, char *line)
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
    free_split(split);
    return (0);
}

int camera(t_parse *p, char *line)
{
    char    **split;
    int     i;

    i = 0;
    split = ft_split(line, ' ');
    if (count_nb_elm(split, 4) == 1)
        return (1);
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
    if (count_nb_elm(split, 4) == 1)
        return (1);
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

int check_extra(char **split, t_parse *p)
{
    int i;

    i = 0;
    while(split[i])
    {
        if (ft_isdigit(split[i][0]) == 0)
        {
            if (ft_strcmp(split[i], "CHECKER") == 0)
            {
                p->chk++;
                if (checker(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "STRIPE") == 0)
            {
                p->str++;
                if (stripe(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "TSY") == 0)
            {
                p->tsy++;
                if (transparency(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "RFR") == 0)
            {
                p->rfr++;
                if (refraction(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "RFL") == 0)
            {
                p->rfl++;
                if (reflection(split, p) == 1)
                    return (1);
            }
        }
        i++;
    }
    if (p->chk > 1 || p->str > 1 || p->tsy > 1 || p->rfr > 1 || p->rfl > 1)
    {
        free_split(split);
        return (1);
    }
    return (0);
}

int plan(t_parse *p, char *line)
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
            return (1);
    }
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
            return (1);
    }
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
    split = ft_split(line, ' ');
        if (count_nb_elm(split, 6) == 2)
    {
        free_split(split);
        return (1);
    }
    else if (count_nb_elm(split, 4) == 1)
    {
        if (check_extra(split, p) == 1)
            return (1);
        if (count_nb_elm(split, 6 + p->count) == 1)
            return (1);
    }
    if (check_xyz(p, split) == 1 || check_diameter(split[3]) == 1 ||
        check_diameter(split[4]) == 1 || check_rgb(split[5], p) == 1)
    {
        free_split(split);
        return (1);
    }
    split_tmp = ft_split(split[2], ',');
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

int cone(t_parse *p, char *line)
{
    if (cylinder(p, line) == 1)
        return (1);
    return (0);
}
