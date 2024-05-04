#include "parse.h"

int checker(char **arg, t_parse *p)
{
    int i;

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
    p->count += 3;
    return (0);
}

int stripe(char **arg, t_parse *p)
{
    int i;
    int j;

    i = 0;
    j = -1;
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
    while (arg[i + 3][++j])
    {
        if (ft_isdigit(arg[i + 3][j]) == 0)
        {
            free_split(arg);
            return (1);
        }
    }
    j = -1;
    while (arg[i + 4][++j])
    {
        if (ft_isdigit(arg[i + 4][++j]) == 0)
        {
            free_split(arg);
            return (1);
        }
    }
    p->count += 5;
    return (0);
}

int transparency(char **arg, t_parse *p)
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
    p->count += 2;
    return (0);
}

int refraction(char **arg, t_parse *p)
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
    p->count += 2;
    return (0);
}

int reflection(char **arg, t_parse *p)
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
    p->count += 2;
    return (0);
}
