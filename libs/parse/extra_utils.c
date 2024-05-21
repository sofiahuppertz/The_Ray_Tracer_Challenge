#include "parse.h"

int checker_error(char **arg, t_parse *p, int i)
{
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
    return (0);
}

int stripe_error(char **arg, t_parse *p, int i)
{
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
    return (0);
}

int transparency_error(char **arg, char *tmp, int i)
{
    if (!arg[i + 1])
    {
        free_split(arg);
        free(tmp);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 0.0 && ft_atof(arg[i + 1]) <= 1.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        free(tmp);
        return (1);
    }
    free(tmp);
    return (0);
}

int refraction_error(char **arg, char *tmp, int i)
{
    if (!arg[i + 1])
    {
        free(tmp);
        free_split(arg);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 1.0 && ft_atof(arg[i + 1]) <= 3.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        free(tmp);
        return (1);
    }
    return (0);
}

int reflection_error(char **arg, char *tmp, int i)
{
    if (!arg[i + 1])
    {
        free_split(arg);
        free(tmp);
        return (1);
    }
    if (!(ft_atof(arg[i + 1]) >= 0.0 && ft_atof(arg[i + 1]) <= 1.0) ||
        arg[i + 1][0] == '-')
    {
        free_split(arg);
        free(tmp);
        return (1);
    }
    return (0);
}
