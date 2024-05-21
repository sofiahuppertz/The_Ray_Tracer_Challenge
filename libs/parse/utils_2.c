#include "parse.h"

double ft_atof(char *str)
{
    char    *endptr;
    double  value;

    value = strtod(str, &endptr);
    return (value);
}

char    *rm_space_malloc(char *str, char *new)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    new = NULL;
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
            || str[i] == '.')
            j++;
        i++;
    }
    new = malloc(sizeof(char) * (j + 1));
    if (!new)
        return (NULL);
    return (new);
}

char    *rm_space(char *str)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    j = 0;
    new = NULL;
    new = rm_space_malloc(str, new);
    if (!new)
        return (NULL);
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
            || str[i] == '.')
        {
            new[j] = str[i];
            j++;
        }
        i++;
    }
    if (!new)
        return (NULL);
    new[j] = '\0';
    return (new);
}

char    *rewrite_extra_alpha_malloc(char *str, char *new)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            while (str[i] >= 'A' && str[i] <= 'Z' && str[i] != '\0' && str[i] != 32 && str[i] != 9)
            {
                j++;
                i++;
            }
            break ;
        } 
        i++;
    }
    new = malloc(sizeof(char) * (j + 1));
    if (!new)
        return (NULL);
    return (new);
}

char    *rewrite_extra_alpha(char *str)
{
    char    *new;
    int     i;
    int     j;

    i = -1;
    j = -1;
    new = NULL;
    new = rewrite_extra_alpha_malloc(str, new);
    if (!new)
        return (NULL);
    while (str[++i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            while (str[i] >= 'A' && str[i] <= 'Z')
                new[++j] = str[i++];
            new[++j] = '\0';
            if (new[0] != '\0')
                return (new);
        } 
    }
    free(new);
    return (NULL);
}

// char    *rm_space(char *str)
// {
//     char    *new;
//     int     i;
//     int     j;

//     i = 0;
//     j = 0;
//     new = NULL;
//     while (str[i])
//     {
//         if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
//             || str[i] == '.')
//             j++;
//         i++;
//     }
//     new = malloc(sizeof(char) * (j + 1));
//     if (!new)
//         return (NULL);
//     j = 0;
//     i = 0;
//     while (str[i])
//     {
//         if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
//             || str[i] == '.')
//         {
//             new[j] = str[i];
//             j++;
//         }
//         i++;
//     }
//     if (!new)
//         return (NULL);
//     new[j] = '\0';
//     return (new);
// }

// char    *rewrite_extra_alpha(char *str)
// {
//     char    *tmp;
//     int     i;
//     int     j;

//     i = 0;
//     j = 0;
//     while (str[i])
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             while (str[i] >= 'A' && str[i] <= 'Z' && str[i] != '\0' && str[i] != 32 && str[i] != 9)
//             {
//                 j++;
//                 i++;
//             }
//             break ;
//         } 
//         i++;
//     }
//     tmp = malloc(sizeof(char) * (j + 1));
//     if (!tmp)
//         return (NULL);
//     i = 0;
//     j = 0;
//     while (str[i])
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             while (str[i] >= 'A' && str[i] <= 'Z')
//             {
//                 tmp[j] = str[i];
//                 j++;
//                 i++;
//             }
//             tmp[j] = '\0';
//             if (tmp[0] != '\0')
//                 return (tmp);
//         } 
//         i++;
//     }
//     free(tmp);
//     return (NULL);
// }
