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
    if (checker_error(arg, p, i) == 1)
        return (1);
    p->color = ft_split(arg[i + 1], ',');
    p->color_2 = ft_split(arg[i + 2], ',');
    p->checker_attr = checker(color(ft_atoi(p->color[0]), ft_atoi(p->color[1]),
        ft_atoi(p->color[2])), color(ft_atoi(p->color_2[0]), ft_atoi(p->color_2[1]),
        ft_atoi(p->color_2[2])));
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
    if (stripe_error(arg, p, i) == 1)
        return (1);
    p->color = ft_split(arg[i + 1], ',');
    p->color_2 = ft_split(arg[i + 2], ',');
    p->stripe_attr = stripe(color(div_255(ft_atoi(p->color[0])), div_255(ft_atoi(p->color[1])),
        div_255(ft_atoi(p->color[2]))), color(div_255(ft_atoi(p->color_2[0])), div_255(ft_atoi(p->color_2[1])),
        div_255(ft_atoi(p->color_2[2]))), ft_atof(arg[i + 3]), ft_atof(arg[i + 4]));
    params_order(p->stripe_attr, p);
    free_split(p->color);
    free_split(p->color_2);
    p->count += 5;
    return (0);
}

int parse_transparency(char **arg, t_parse *p)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    while (arg[i])
    {
        tmp = rewrite_extra_alpha(arg[i]);
        if (tmp)
        {
            if (ft_strcmp(tmp, "TSY") == 0)
            {
                if (transparency_error(arg, tmp, i) == 1)
                    return (1);
                p->transparency_attr = tsy(ft_atof(arg[i + 1]));
                params_order(p->transparency_attr, p);
                p->count += 2;
                break ;
            }
            if (tmp)
                free(tmp);
        }
        i++;
    }
    return (0);
}

int parse_refraction(char **arg, t_parse *p)
{
    char    *tmp;
    int     i;

    i = -1;
    tmp = NULL;
    while (arg[++i])
    {
        tmp = rewrite_extra_alpha(arg[i]);
        if (tmp)
        {
            if (ft_strcmp(tmp, "RFR") == 0)
            {
                if (refraction_error(arg, tmp, i) == 1)
                    return (1);
                p->refraction_attr = rfr(ft_atof(arg[i + 1]));
                params_order(p->refraction_attr, p);
                p->count += 2;
                free(tmp);
                break ;
            }
            if (tmp)
                free(tmp);
        }
    }
    return (0);
}

int parse_reflection(char **arg, t_parse *p)
{
    char    *tmp;
    int     i;

    i = -1;
    tmp = NULL;
    while (arg[++i])
    {
        tmp = rewrite_extra_alpha(arg[i]);
        if (tmp)
        {
            if (ft_strcmp(tmp, "RFL") == 0)
            {
                if (reflection_error(arg, tmp, i) == 1)
                    return (1);
                p->reflection_attr = rfl(ft_atof(arg[i + 1]));
                params_order(p->reflection_attr, p);
                p->count += 2;
                free(tmp);
                break ;
            }
            if (tmp)
                free(tmp);
        }
    }
    return (0);
}
