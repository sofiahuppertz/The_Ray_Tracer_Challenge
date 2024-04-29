#include "parse.h"

int ambiant_light(t_parse *p, char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    p->ratio = custom_atof(split[1]);
    // p->color = line[2];
    printf("%.1f\n", p->ratio);
    // printf("%s\n", p->color);
    return (0);
}

int parse(t_parse *p, char *line)
{
    if (ft_strncmp("A", line, 1) == 0)
    {
        if (ambiant_light(p, line) == 1)
            return (1);
    }
    // else if (ft_strncmp("C", line, 1) == 0)
    // {
    //     if (camera() == 1)
    //         return (1);
    // }
    // else if (ft_strncmp("L", line, 1) == 0)
    // {
    //     if (light() == 1)
    //         return (1);
    // }
    // else if (ft_strncmp("pl", line, 2) == 0)
    // {
    //     if (plan() == 1)
    //         return (1);
    // }
    // else if (ft_strncmp("sp", line, 2) == 0)
    // {
    //     if (sphere() == 1)
    //         return (1);
    // }
    // else if (ft_strncmp("cy", line, 2) == 0)
    // {
    //     if (cylinder() == 1)
    //         return (1);
    // }
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
        if (strcmp(tmp, ".rt") != 0)
        {
            printf("error: please enter a file.rt\n");
            return (1);
        }
        return (0);
    }
    printf("error: number of arg should be 2\n");
    return (1);
}

int    parsing_error(int tmp, int fd)
{
    if (tmp == 1)
    {
        printf("Parsing error: incorrect character(s) or number(s) in map");
        close(fd);
        return (1);
    }
    return (0);
}

int check_file_rt(int fd)
{
    t_parse p;
    char    *line;
    int     res;
    int     tmp;

    res = 1;
    tmp = 0;
    while (res)
    {
        res = read_line(fd, &line, 4096);
        if (parse(&p, line) == 1)
            tmp = 1;
        free(line);
        if (!res)
            break ;
        if (tmp == 1)
            return (1);
    }
    if (parsing_error(tmp, fd) == 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int   fd;

    if (check_cmd_line(ac, av) == 1)
        return (1);
    fd = open(av[ac - 1], O_RDONLY);
    if (!fd)
    {
        perror("fd");
        return (1);
    }
    if (check_file_rt(fd) == 1)
        return (1);
    close(fd);
    return (0);
}
