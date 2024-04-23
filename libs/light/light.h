#ifndef LIGHT_H
# define LIGHT_H

#include "../tuple/tuple.h"
#include "../color/color.h"
#include "../pattern/pattern.h"

typedef struct s_point_light 
{
    t_color *intensity;
    t_tuple *position;
} t_point_light;


typedef struct s_material
{
    t_pattern *pattern;
    t_color *color;
    double ambient;
    double diffuse;
    double specular;
    double shininess;
} t_material;


// Phong reflection model
t_color *lighting(const t_material material, const t_point_light light, const t_tuple position, const t_tuple eyev, const t_tuple normalv, int in_shadow);


// Point Light
t_point_light *point_light(t_color *intensity, t_tuple *position);
void free_point_light(t_point_light **light);
void print_point_light(const t_point_light light);


// Material

// Constructor
t_material *default_material(void);
t_material *material(t_color *color, double ambient, double diffuse, double specular, double shininess);
t_material *materialcpy(const t_material material);

// Methods
void print_material(const t_material material);

// Setters
void set_color(t_material *material, t_color *color);
void set_pattern(t_material *material, t_pattern *pattern);
void remove_pattern(t_material *material);

// Destructor
void free_material(t_material **material);


#endif