#include "parse.h"

int parse_checker(char **arg, t_parse *p)
{
    int     i;

    i = 0;
    while (arg[i])
    {
        if (ft_strcmp(arg[i], "CHECKER") == 0)
            break ;
        i++;
    }
    if (!arg[i + 1])
    {
        free_split(arg);
        return (1);
    }
    if (!arg[i + 2])
    {
        free_split(arg);
        return (1);
    }
    if (check_rgb(arg[i + 1], p) == 1 || check_rgb(arg[i + 2], p) == 1)
    {
        free_split(arg);
        return (1);
    }
    p->color = ft_split(arg[i + 1], ',');
    // p->chk_fc = color(ft_atoi(p->color[0]), ft_atoi(p->color[1]), ft_atoi(p->color[2]));
    free_split(p->color);
    p->color = ft_split(arg[i + 2], ',');
    // p->chk_sc = color(ft_atoi(p->color[0]), ft_atoi(p->color[1]), ft_atoi(p->color[2]));
    free_split(p->color);
    p->count += 3;
    return (0);
}

int parse_stripe(char **arg, t_parse *p)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strcmp(arg[i], "STRIPE") == 0)
            break ;
        i++;
    }
    if (!arg[i + 1])
    {
        free_split(arg);
        return (1);
    }
    if (!arg[i + 2])
    {
        free_split(arg);
        return (1);
    }
    if (check_rgb(arg[i + 1], p) == 1 || check_rgb(arg[i + 2], p) == 1)
    {
        free_split(arg);
        return (1);
    }
    if (check_diameter(arg[i + 3], p) == 1 || check_diameter(arg[i + 4], p) == 1)
    {
        free_split(arg);
        return (1);
    }
    p->color = ft_split(arg[i + 1], ',');
    // p->str_fc = color(ft_atoi(p->color[0]), ft_atoi(p->color[1]), ft_atoi(p->color[2]));
    free_split(p->color);
    p->color = ft_split(arg[i + 2], ',');
    // p->str_sc = color(ft_atoi(p->color[0]), ft_atoi(p->color[1]), ft_atoi(p->color[2]));
    free_split(p->color);
    p->str_width = ft_atof(arg[i + 3]);
    p->str_rot = ft_atof(arg[i + 4]);
    p->count += 5;
    return (0);
}

int parse_transparency(char **arg, t_parse *p)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strcmp(arg[i], "TSY") == 0)
            break ;
        i++;
    }
    if (!arg[i + 1])
    {
        free_split(arg);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 0.0 && ft_atof(arg[i + 1]) <= 1.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        return (1);
    }
    p->tsy_range = ft_atof(arg[i + 1]);
    p->count += 2;
    return (0);
}

int parse_refraction(char **arg, t_parse *p)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strcmp(arg[i], "RFR") == 0)
            break ;
        i++;
    }
    if (!arg[i + 1])
    {
        free_split(arg);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 1.0 && ft_atof(arg[i + 1]) <= 3.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        return (1);
    }
    p->rfr_range = ft_atof(arg[i + 1]);
    p->count += 2;
    return (0);
}

int parse_reflection(char **arg, t_parse *p)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strcmp(arg[i], "RFL") == 0)
            break ;
        i++;
    }
    if (!arg[i + 1])
    {
        free_split(arg);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 0.0 && ft_atof(arg[i + 1]) <= 1.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        return (1);
    }
    p->rfl_range = ft_atof(arg[i + 1]);
    p->count += 2;
    return (0);
}
