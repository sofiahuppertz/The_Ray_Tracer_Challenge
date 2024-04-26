#ifndef PATTERN_H
#define PATTERN_H

#include "../color/color.h"
#include "../tuple/tuple.h"


typedef  t_color *(*t_pattern_at)(void *, const t_tuple);


typedef struct s_pattern
{
    t_tf tf;
    t_matrix *tr;
    t_color *a;
    t_color *b;
    t_pattern_at local_pattern;
} t_pattern;


// Constructor
t_pattern *abstract_pattern(t_color *a, t_color *b);
void pattern(t_color *a, t_color *b, t_pattern *pattern);
t_pattern *patterncpy(const t_pattern pattern);

// Methods
void print_pattern(const t_pattern pattern);
void set_pattern_tr(void *s, t_matrix *transformation);

// Destructor
void free_pattern(t_pattern **p);

t_pattern *stripe(t_color *a, t_color *b);
t_color *stripe_at(void *pattern, const t_tuple point);


# endif