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

int    parsing_error(int tmp, int fd)
{
    if (tmp == 1)
    {
        printf("Parsing error: incorrect character(s) or number(s) in map\n");
        close(fd);
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

double	ft_atof(char *str)
{
	int	    i;
    int     sign;
    int     hasfract;
	double	res;
	double	tmp;
    double  fract;

	i = 0;
    sign = 1;
    res = 0.0;
    tmp = 0.0;
    fract = 0.0;
    hasfract = 0;
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
            i++;
        }
        hasfract = 1;
    }
    tmp = res;
    res = res + (fract / 10);
    if (!hasfract)
    {
        res = tmp;
    }
	return (res * sign);
}
