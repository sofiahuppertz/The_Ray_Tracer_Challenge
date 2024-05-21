#include "parse.h"

int identify_2(t_parse *p, char *line)
{
    if (ft_strncmp("pl", line, 2) == 0)
    {
        if (parse_plan(p, line) == 1)
            return (1);
    }
    else if (ft_strncmp("sp", line, 2) == 0)
    {
        if (parse_sphere(p, line) == 1)
            return (1);
    }
    else if (ft_strncmp("cy", line, 2) == 0)
    {
        if (parse_cylinder(p, line) == 1)
            return (1);
    }
    else if (ft_strncmp("co", line, 2) == 0)
    {
        if (parse_cone(p, line) == 1)
            return (1);
    }
    return (0);
}

int identify(t_parse *p, char *line)
{
    if (check_id(line) == 1)
        return (1);
    if (ft_strncmp("A", line, 1) == 0)
    {
        p->A++;
        if (parse_ambiant_light(p, line) == 1)
            return (1);
    }
    else if (ft_strncmp("C", line, 1) == 0)
    {
        p->C++;
        if (parse_camera(p, line) == 1)
            return (1);
    }
    else if (ft_strncmp("L", line, 1) == 0)
    {
        p->L++;
        if (parse_light(p, line) == 1)
            return (1);
    }
    else if (identify_2(p, line) == 1)
        return (1);
    return (0);
}

int check_cmd_line(int ac, char **av)
{
    char    *tmp;
    int     last_arg;

    last_arg = ac - 1;
    if (ac == 2)
    {
        tmp = strrchr(av[last_arg], '.');
        if (tmp)
        {
            if (strcmp(tmp, ".rt") != 0)
            {
                printf("error: please enter a file.rt\n");
                return (1);
            }
            return (0);
        }
    }
    printf("error: number of arg should be 2\n");
    return (1);
}

void    init(t_parse *p)
{
    p->count = 0;
    p->chk = 0;
    p->str = 0;
    p->tsy = 0;
    p->rfr = 0;
    p->rfl = 0;
    p->checker_attr = NULL;
    p->stripe_attr = NULL;
    p->transparency_attr = NULL;
    p->refraction_attr = NULL;
    p->reflection_attr = NULL;

    p->params[0] = NULL;
    p->params[1] = NULL;
    p->params[2] = NULL;
    p->params[3] = NULL;
    p->params[4] = NULL;
    p->params[5] = NULL;
}

int check_file_rt(int fd)
{
    t_parse p;
    char    *line;
    int     res;
    int     tmp;

    res = 1;
    tmp = 0;
    p.A = 0;
    p.L = 0;
    p.C = 0;
    while (res)
    {
        res = read_line(fd, &line, 4096);
        init(&p);
        if (identify(&p, line) == 1)
            tmp = 1;
        free(line);
        if (!res)
            break ;
    }
    if (parsing_error(tmp, fd, &p) == 1)
        return (1);
    return (0);
}
