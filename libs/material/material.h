#ifndef MATERIAL_H
#define MATERIAL_H


#include "../pattern/pattern.h"


#define Vacuum 1.0
#define Air  1.00029
#define Water 0.333
#define Glass 1.52
#define Diamond 2.417



typedef struct s_material
{
    t_pattern *pattern;
    double ambient;
    double diffuse;
    double specular;
    double shininess;
    double reflective;
    double transparency;
    double refrac_index;
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
void set_ambient(t_material *material, double ambient);
void set_diffuse(t_material *material, double diffuse);
void set_specular(t_material *material, double specular);
void set_shininess(t_material *material, double shininess);
void set_reflective(t_material *material, double reflective);
void set_transparency(t_material *material, double transparency);
void set_refrac_index(t_material *material, double refrac_index);
void remove_pattern(t_material *material);

// Destructor
void free_material(t_material **material);

#endif