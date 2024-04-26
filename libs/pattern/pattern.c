#include "pattern.h"

t_pattern *abstract_pattern(t_color *a, t_color *b)
{
    t_pattern *pattern;
    
    pattern = NULL;
    pattern = calloc(1, sizeof(t_pattern));
    if (!pattern)
    {
        printf("Error: stripe_pattern : calloc failed.\n");
        return NULL; 
    }
    pattern->a = a;
    pattern->b = b;
    pattern->tf.type = PATTERN;
    pattern->tf.transform = set_pattern_tr;
    pattern->tr = identity(4);
    pattern->local_pattern = NULL;
    pattern->next = NULL;
    return pattern;

}

void pattern(t_color *a, t_color *b, t_pattern *pattern)
{
    pattern->a = a;
    pattern->b = b;
    pattern->tf.type = PATTERN;
    pattern->tf.transform = set_pattern_tr;
    pattern->tr = identity(4);
    pattern->local_pattern = NULL;
    pattern->next = NULL;
}

void free_pattern(t_pattern **p)
{
    t_pattern *curr;
    t_pattern *next;

    curr = *p;
    while (curr)
    {
        next = curr->next;
        free(curr->a);
        if (curr->b)
            free(curr->b);
        free_matrix(&curr->tr);
        free(curr);
        curr = next;
    }
    *p = NULL;
}

