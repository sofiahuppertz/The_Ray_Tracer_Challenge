/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:58 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/19 19:23:00 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
#define PATTERN_H

#include "../color/color.h"
#include "../tuple/tuple.h"

typedef t_color *(*t_pattern_at)(void *, const t_tuple);

typedef struct s_pattern
{
    t_tf tf;
    t_matrix *tr;
    t_color *a;
    t_color *b;
    t_pattern_at local_pattern;
    struct s_pattern *next;
} t_pattern;

// Constructor
t_pattern *abstract_pattern(t_color *a, t_color *b);
void pattern(t_color *a, t_color *b, t_pattern *pattern);
t_pattern *patterncpy(const t_pattern pattern);

// Methods
void print_pattern(const t_pattern pattern);
void set_pattern_tr(void *s, t_matrix *transformation);
void add_pattern(t_pattern **list, t_pattern *pattern);

// Destructor
void free_pattern(t_pattern **p);

// Test pattern
t_pattern *test_pattern(void);
t_color *test_pattern_at(void *pattern, const t_tuple point);

// Stripe
t_pattern *stripe_pattern(t_color *a, t_color *b);
t_color *stripe_at(void *pattern, const t_tuple point);

// Gradient
t_pattern *gradient(t_color *a, t_color *b);
t_color *gradient_at(void *pattern, const t_tuple point);

// Ring
t_pattern *ring(t_color *a, t_color *b);
t_color *ring_at(void *pattern, const t_tuple point);

// Checker
t_pattern *checker_pattern(t_color *a, t_color *b);
t_color *checker_at(void *pattern, const t_tuple point);

// Solid
t_pattern *solid(t_color *a);
t_color *solid_at(void *pattern, const t_tuple point);
t_pattern *blended(t_pattern *patterns);
t_color *blended_at(void *pattern, const t_tuple point);

#endif