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
    if (vector_range(split, p) == 1 || check_xyz(p, split) == 1)
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
	make_light(point(p->x, p->y, p->z), ft_atof(split[2]), color(div_255(p->r), div_255(p->g), div_255(p->b)));
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
                if (parse_checker(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "STRIPE") == 0)
            {
                p->str++;
                if (parse_stripe(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "TSY") == 0)
            {
                p->tsy++;
                if (parse_transparency(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "RFR") == 0)
            {
                p->rfr++;
                if (parse_refraction(split, p) == 1)
                    return (1);
            }
            else if (ft_strcmp(split[i], "RFL") == 0)
            {
                p->rfl++;
                if (parse_reflection(split, p) == 1)
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
        {
            free_split(split);
            return (1);
        }
        if (count_nb_elm(split, 4 + p->count) == 1)
        {
            printf("4 + p->count(%d) = %d\n\n", p->count, 4 + p->count);
            free_split(split);
            return (1);
        }
    }
    if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1 ||
        vector_range(split, p) == 1)
    {
        free_split(split);
        return (1);
    }
	make_plane(point(p->x, p->y, p->z), vector(p->vr_1, p->vr_2, p->vr_3),
        color(div_255(p->r), div_255(p->g), div_255(p->b)), p->params[0],
        p->params[1], p->params[2], p->params[3], p->params[4], p->params[5]);
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
        if (check_extra(split, p) == 1)
        {
            free_split(split);
            return (1);
        }
        if (count_nb_elm(split, 4 + p->count) == 1)
        {
            free_split(split);
            return (1);
        }
    }
    if (check_xyz(p, split) == 1 || check_rgb(split[3], p) == 1 ||
        check_diameter(split[2], p) == 1)
    {
        free_split(split);
        return (1);
    }
	make_sphere(point(p->x, p->y, p->z), p->diam, color(div_255(p->r), div_255(p->g),
        div_255(p->b)), p->params[0], p->params[1], p->params[2], p->params[3],
        p->params[4], p->params[5]);
    free_split(split);
    return (0);
}

int parse_cylinder(t_parse *p, char *line, char *n)
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
    if (check_xyz(p, split) == 1 || check_diameter(split[3], p) == 1 ||
        check_diameter(split[4], p) == 1 || check_rgb(split[5], p) == 1 || vector_range(split, p) == 1)
    {
        free_split(split);
        return (1);
    }
    split_tmp = ft_split(split[2], ',');
    while (split_tmp[i])
    {
        if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1)
        {
            free_split(split);
            free_split(split_tmp);
            return (1);
        }
        i++;
    }
    if (ft_strcmp(n, "cy") == 0)
    {
	    make_cylinder(point(p->x, p->y, p->z), vector(p->vr_1, p->vr_2, p->vr_3),
            ft_atof(split[3]), ft_atof(split[4]), color(div_255(p->r), div_255(p->g),
            div_255(p->b)), p->params[0], p->params[1], p->params[2], p->params[3],
            p->params[4], p->params[5]);
    }
    else if (ft_strcmp(n, "co") == 0)
    {
        make_cone(point(p->x, p->y, p->z), vector(p->vr_1, p->vr_2, p->vr_3),
            ft_atof(split[3]), ft_atof(split[4]), color(div_255(p->r), div_255(p->g),
            div_255(p->b)), p->params[0], p->params[1], p->params[2], p->params[3],
            p->params[4], p->params[5]);
    }
    free_split(split);
    free_split(split_tmp);
    return (0);
}

int parse_cone(t_parse *p, char *line)
{
    if (parse_cylinder(p, line, "co") == 1)
        return (1);
    return (0);
    //     char    **split_tmp;
    // char    **split;
    // int     i;

    // i = 0;
    // split = ft_split(line, ' ');
    //     if (count_nb_elm(split, 6) == 2)
    // {
    //     free_split(split);
    //     return (1);
    // }
    // else if (count_nb_elm(split, 4) == 1)
    // {
    //     if (check_extra(split, p) == 1)
    //         return (1);
    //     if (count_nb_elm(split, 6 + p->count) == 1)
    //         return (1);
    // }
    // if (check_xyz(p, split) == 1 || check_diameter(split[3], p) == 1 ||
    //     check_diameter(split[4], p) == 1 || check_rgb(split[5], p) == 1)
    // {
    //     free_split(split);
    //     return (1);
    // }
    // split_tmp = ft_split(split[2], ',');
    // while (split_tmp[i])
    // {
    //     if (ft_atof(split_tmp[i]) < -1 || ft_atof(split_tmp[i]) > 1)
    //     {
    //         free_split(split);
    //         free_split(split_tmp);
    //         return (1);
    //     }
    //     i++;
    // }
	// make_cylinder(point(p->x, p->y, p->z), vector(p->vr_1, p->vr_2, p->vr_3),
    //     ft_atof(split[3]), ft_atof(split[4]), color(div_255(p->r), div_255(p->g),
    //     div_255(p->b)), p->params[0], p->params[1], p->params[2], p->params[3],
    //     p->params[4], p->params[5]);
    // free_split(split);
    // free_split(split_tmp);
    return (0);
}
