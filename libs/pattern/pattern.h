#ifndef PATTERN_H
#define PATTERN_H


#include "../color/color.h"
#include "../tuple/tuple.h"

typedef struct s_pattern
{
    t_color *a;
    t_color *b;
} t_pattern;

// Constructor
//t_pattern *default_pattern( void );
t_pattern *stripe_pattern(t_color *a, t_color *b);
t_pattern *patterncpy(const t_pattern pattern);

// Methods
t_color *stripe_at(const t_pattern *p, const t_tuple point);


// Destructor
void free_pattern(t_pattern **p);

#endif