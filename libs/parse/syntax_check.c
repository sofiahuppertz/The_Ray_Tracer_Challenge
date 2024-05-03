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
            if (p->color[i][j] != 13 && p->color[i][j] != ',' && ft_isdigit(p->color[i][j]) == 0)
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
    free_split(p->color);
    return (0);
}

int check_range(char **split, t_parse *p)
{
    p->ratio = ft_atof(split[1]);
    if (!(p->ratio >= 0.0 && p->ratio <= 1.0) || split[1][0] == '-')
        return (1);
    return (0);
}

int vector_range(char **split)
{
    char    **split_tmp;
    int     i;
    int     j;

    i = 0;
    split_tmp = ft_split(split[2], ',');
    while (split_tmp[i])
    {
        if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1)
        {
            free_split(split_tmp);
            return (1);
        }
        j = 0;
        while (split_tmp[i][j])
        {
            if (split_tmp[i][0] == '+' || split_tmp[i][0] == '-')
                j++;
            if ((ft_isdigit(split_tmp[i][0]) != 0 || split_tmp[i][0] == '+' ||
                split_tmp[i][0] == '-') && split_tmp[i][j] == '.')
                j++;
            if (split_tmp[i][j] && ft_isdigit(split_tmp[i][j]) == 0)
            {
                free_split(split_tmp);
                return (1);
            }
            j++;
        }
        i++;
    }
    free_split(split_tmp);
    if (count_comma(split[2]) == 1 || i != 3)
        return (1);
    return (0);
}


int check_xyz(t_parse *p, char **split)
{
    char    **split_tmp;
    int     i;
    int     j;

    i = -1;
    (void)p;
    split_tmp = ft_split(split[1], ',');
    if (!split_tmp[2])
    {
        free_split(split_tmp);
        return (1);
    }
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
    free_split(split_tmp);
    return (0);
}

int check_diameter(char *diameter)
{
    int i;

    i = 0;
    if (diameter[0] == '-')
        return (1);
    while (diameter[i])
    {
        if (ft_isdigit(diameter[0]) != 0 && diameter[i] == '.')
            i++;
        if (ft_isdigit(diameter[i]) == 0)
        {
        printf("%s\n", diameter);
        printf("%c\n", diameter[i]);

            return (1);
        }
        i++;
    }
    return (0);
}
