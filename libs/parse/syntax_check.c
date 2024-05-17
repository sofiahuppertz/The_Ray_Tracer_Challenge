#include "parse.h"

int check_rgb(char *split, t_parse *p)
{
    int i;
    int j;

    i = 0;
    p->color = ft_split(split, ',');
    while (p->color[i])
    {
        j = -1;
        if (ft_atoi(p->color[i]) < 0 || ft_atoi(p->color[i]) > 255)
        {
            free_split(p->color);
            return (1);
        }
        while(p->color[i][++j])
        {
            if (p->color[i][j] != 13 && p->color[i][j] != ',' &&
                ft_isdigit(p->color[i][j]) == 0 && p->color[i][j] != 9)
            {
                free_split(p->color);
                return (1);
            }
        }
        i++;
    }
    if (i != 3 || p->color[2][0] == 13 || count_comma(split) == 1)
    {
        free_split(p->color);
        return (1);
    }
    p->r = ft_atoi(p->color[0]);
    p->g = ft_atoi(p->color[1]);
    p->b = ft_atoi(p->color[2]);
    free_split(p->color);
    return (0);
}

int check_range(char **split, t_parse *p)
{
    (void)p;
    if (!split[1])
        return (1);
    if (!(ft_atof(split[1]) >= 0.0 && ft_atof(split[1]) <= 1.0) || split[1][0] == '-')
        return (1);
    return (0);
}

int vector_range(char **split, t_parse *p)
{
    char    **split_tmp;
    char    *tmp;
    int     i;
    int     j;

    i = 0;
    tmp = NULL;
    split_tmp = ft_split(split[2], ',');
    while (split_tmp[i])
    {
        if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1)
        {
            free_split(split_tmp);
            return (1);
        }
        j = 0;
        tmp = rm_space(split_tmp[i]);
        if (tmp)
        {
            while (tmp[j])
            {
                if (j == 0 && (tmp[j] == '+' || tmp[j] == '-'))
                    j++;
                else if ((ft_isdigit(tmp[0]) != 0 || tmp[0] == '+' ||
                    tmp[0] == '-') && tmp[j] == '.')
                    j++;
                if (tmp[j] && ft_isdigit(tmp[j]) == 0 && tmp[j] != 9)
                {
                    free_split(split_tmp);
                    free(tmp);
                    return (1);
                }
                if (!tmp[j])
                    break ;
                j++;
            }
            free(tmp);
        }
        i++;
    }
    if (count_comma(split[2]) == 1 || i != 3)
    {
        free_split(split_tmp);
        return (1);
    }
    p->vr_1 = ft_atof(split_tmp[0]);
    p->vr_2 = ft_atof(split_tmp[1]);
    p->vr_3 = ft_atof(split_tmp[2]);
    free_split(split_tmp);
    return (0);
}

int check_xyz(t_parse *p, char **split)
{
    char    **split_tmp;
    int     i;
    int     j;

    i = -1;
    split_tmp = ft_split(split[1], ',');
    while (split_tmp[++i])
    {
        j = -1;
        if (split_tmp[i][0] == '+' || split_tmp[i][0] == '-')
            j++;
        while (split_tmp[i][++j])
        {
            if ((ft_isdigit(split_tmp[i][0]) == 1 || split_tmp[i][0] == '+' ||
                split_tmp[i][0] == '-') && split_tmp[i][j] == '.')
                j++;
            if (count_comma(split[1]) == 1 || ft_isdigit(split_tmp[i][j]) == 0)
            {
                free_split(split_tmp);
                return (1);
            }
        }
    }
    if (i != 3)
    {
        free_split(split_tmp);
        return (1);
    }
    p->x = ft_atof(split_tmp[0]);
    p->y = ft_atof(split_tmp[1]);
    p->z = ft_atof(split_tmp[2]);
    free_split(split_tmp);
    return (0);
}

int check_diameter(char *diameter, t_parse *p)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    if (diameter[0] == '-')
        return (1);
    tmp = rm_space(diameter);
    if (tmp)
    {
        while (tmp[i])
        {
            if (ft_isdigit(tmp[0]) != 0 && tmp[i] == '.')
                i++;
            if (ft_isdigit(tmp[i]) == 0)
            {
                free(tmp);
                return (1);
            }
            i++;
        }
        p->diam = ft_atof(tmp);
        free(tmp);
    }
    return (0);
}
