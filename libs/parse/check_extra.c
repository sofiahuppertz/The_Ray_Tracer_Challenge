/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:11 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 11:09:11 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	params_order(t_attributes *extra, t_parse *p)
{
	if (!p->params[0])
		p->params[0] = extra;
	else if (!p->params[1])
		p->params[1] = extra;
	else if (!p->params[2])
		p->params[2] = extra;
	else if (!p->params[3])
		p->params[3] = extra;
	else if (!p->params[4])
		p->params[4] = extra;
}

int	check_third(char **split, char *tmp, t_parse *p)
{
	if (ft_strcmp(tmp, "RFL") == 0)
	{
		p->rfl++;
		if (parse_reflection(split, p) == 1)
		{
			free(tmp);
			return (1);
		}
	}
	return (0);
}

int	check_sec(char **split, char *tmp, t_parse *p)
{
	if (ft_strcmp(tmp, "TSY") == 0)
	{
		p->tsy++;
		if (parse_transparency(split, p) == 1)
		{
			free(tmp);
			return (1);
		}
	}
	else if (ft_strcmp(tmp, "RFR") == 0)
	{
		p->rfr++;
		if (parse_refraction(split, p) == 1)
		{
			free(tmp);
			return (1);
		}
	}
	else if (check_third(split, tmp, p) == 1)
		return (1);
	return (0);
}

int	check_first(char **split, char *tmp, t_parse *p)
{
	if (ft_strcmp(tmp, "CHECKER") == 0)
	{
		p->chk++;
		if (parse_checker(split, p) == 1)
		{
			free(tmp);
			return (1);
		}
	}
	else if (ft_strcmp(tmp, "STRIPE") == 0)
	{
		p->str++;
		if (parse_stripe(split, p) == 1)
		{
			free(tmp);
			return (1);
		}
	}
	else if (check_sec(split, tmp, p) == 1)
		return (1);
	return (0);
}

int	check_extra(char **split, t_parse *p)
{
	char	*tmp;
	int		i;

	i = 0;
	while (split[i])
	{
		tmp = rewrite_extra_alpha(split[i]);
		if (tmp != NULL && ft_isdigit(split[i][0]) == 0)
		{
			if (check_first(split, tmp, p) == 1)
				return (1);
			free(tmp);
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

// int check_extra(char **split, t_parse *p)
// {
//     char    *tmp;
//     int     i;

//     i = 0;
//     while(split[i])
//     {
//         tmp = rewrite_extra_alpha(split[i]);
//         if (tmp != NULL && ft_isdigit(split[i][0]) == 0)
//         {
//             if (ft_strcmp(tmp, "CHECKER") == 0)
//             {
//                 p->chk++;
//                 if (parse_checker(split, p) == 1)
//                 {
//                     free(tmp);
//                     return (1);
//                 }
//             }
//             else if (ft_strcmp(tmp, "STRIPE") == 0)
//             {
//                 p->str++;
//                 if (parse_stripe(split, p) == 1)
//                 {
//                     free(tmp);
//                     return (1);
//                 }
//             }
//             else if (ft_strcmp(tmp, "TSY") == 0)
//             {
//                 p->tsy++;
//                 if (parse_transparency(split, p) == 1)
//                 {
//                     free(tmp);
//                     return (1);
//                 }
//             }
//             else if (ft_strcmp(tmp, "RFR") == 0)
//             {
//                 p->rfr++;
//                 if (parse_refraction(split, p) == 1)
//                 {
//                     free(tmp);
//                     return (1);
//                 }
//             }
//             else if (ft_strcmp(tmp, "RFL") == 0)
//             {
//                 p->rfl++;
//                 if (parse_reflection(split, p) == 1)
//                 {
//                     free(tmp);
//                     return (1);
//                 }
//             }
//             free(tmp);
//         }
//         i++;
//     }
//     if (p->chk > 1 || p->str > 1 || p->tsy > 1 || p->rfr > 1 || p->rfl > 1)
//     {
//         free_split(split);
//         return (1);
//     }
//     return (0);
// }
