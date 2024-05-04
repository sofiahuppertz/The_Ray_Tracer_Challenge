#include "parse.h"

void    free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int    parsing_error(int tmp, int fd, t_parse *p)
{
    close(fd);
    if (p->A != 1 || p->C != 1 || p->L != 1)
    {
        printf("Parsing error: check A, C, L identifiers in map\n");
        return (1);
    }
    if (tmp == 1)
    {
        printf("Parsing error: incorrect character(s) or number(s) in map\n");
        return (1);
    }
    return (0);
}

int count_comma(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
        return (1);
    return (0);
}

int count_nb_elm(char **line, int j)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    if (i > j)
        return (1);
    if (i < j)
    {
        // free_split(line);
        return (2);
    }
    return (0);
}

int check_id(char *line)
{
    if (ft_strncmp("A", line, 1) != 0 && ft_strncmp("C", line, 1) != 0
        && ft_strncmp("L", line, 1) != 0 && ft_strncmp("pl", line, 2) != 0
        && ft_strncmp("sp", line, 2) != 0 && ft_strncmp("cy", line, 2) != 0
        && ft_strncmp("co", line, 2) != 0 && line[0] != 0)
    {
        printf("%d\n", line[0]);
        return (1);
    }
    return (0);
}

double	ft_atof(char *str)
{
	int	    i;
    int     sign;
	double	res;
    double  fract;
    double  div;

	i = 0;
    sign = 1;
    div = 1.0;
    res = 0.0;
    fract = 0.0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
    if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != '.' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
    if (str[i] == '.')
    {
        i++;
	    while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
            fract = fract * 10 + str[i] - '0';
            div *= 10;
            i++;
        }
    }
    res = res + (fract / div);
	return (res * sign);
}
