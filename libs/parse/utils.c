#include "parse.h"

double custom_atof(const char *str)
{
    double result = 0.0;
    int i = 0;
    int sign = 1;
    double divisor = 10.0;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }
    if (str[i] == ',')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result + (str[i] - '0') / divisor;
        divisor *= 10.0;
        i++;
    }
    return (result * sign);
}
