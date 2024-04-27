#ifndef MATERIAL_H
#define MATERIAL_H


#include "../pattern/pattern.h"

typedef struct s_material
{
    t_pattern *pattern;
    double ambient;
    double diffuse;
    double specular;
    double shininess;
    double reflective;
} t_material;


// Material

// Constructor
t_material *default_material(void);
t_material *material(t_pattern *pat, double ambient, double diffuse, double specular, double shininess);
t_material *materialcpy(const t_material material);

// Methods
void print_material(const t_material material);

// Setters
//void set_color(t_material *material, t_color *color);
void set_pattern(t_material *material, t_pattern *pattern);
void remove_pattern(t_material *material);

// Destructor
void free_material(t_material **material);

#endif