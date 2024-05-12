#include "parse.h"

void    params_order(t_attributes *extra, t_parse *p)
{
    if (!p->params[0])
        p->params[0] = extra;
    else if (!p->params[1])
        p->params[1] = extra;
    else if (!p->params[2])
        p->params[2] = extra;
    else if (!p->params[3])
        p->params[3] = extra;
    else if (!p->params[4])
        p->params[4] = extra;
}

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
    p->color_2 = ft_split(arg[i + 2], ',');
    p->checker_attr = checker(color(ft_atoi(p->color[0]), ft_atoi(p->color[1]), ft_atoi(p->color[2])),
        color(ft_atoi(p->color_2[0]), ft_atoi(p->color_2[1]), ft_atoi(p->color_2[2])));
    params_order(p->checker_attr, p);
    free_split(p->color);
    free_split(p->color_2);
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
    p->color_2 = ft_split(arg[i + 2], ',');
    p->stripe_attr = stripe(color(ft_atoi(p->color[0]), ft_atoi(p->color[1]),
        ft_atoi(p->color[2])),color(ft_atoi(p->color_2[0]), ft_atoi(p->color_2[1]),
        ft_atoi(p->color_2[2])), ft_atof(arg[i + 3]), ft_atof(arg[i + 4]));
    params_order(p->stripe_attr, p);
    free_split(p->color);
    free_split(p->color_2);
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
    p->transparency_attr = tsy(ft_atof(arg[i + 1]));
    params_order(p->transparency_attr, p);
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
    p->refraction_attr = rfr(ft_atof(arg[i + 1]));
    params_order(p->refraction_attr, p);
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
    p->reflection_attr = rfl(ft_atof(arg[i + 1]));
    params_order(p->reflection_attr, p);
    p->count += 2;
    return (0);
}
