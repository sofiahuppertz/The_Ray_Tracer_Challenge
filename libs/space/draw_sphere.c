#include "space.h"


static t_color *compute_shade(t_intersection _hit, const t_ray *r, const t_sphere *sp, const t_point_light light)
{
    t_tuple *hit_pos;
    t_tuple *normalv;
    t_tuple *eyev;
    t_color *_color;

    hit_pos = position_at(_hit.t, *r);
    normalv = normal_at(*sp, *hit_pos);
    eyev = tuplecpy(*r->di);
    neg_tuple(eyev);
    _color = lighting(*sp->material, light, *hit_pos, *eyev, *normalv);
    free_tuples(hit_pos, normalv, eyev, NULL);
    return _color;
}


static void compute_hit(const t_coordinates cor, t_space space, t_canvas *_canvas, const t_sphere *sp, const t_point_light light, const t_tuple position)
{
    t_tuple *ray_dir;
    t_tuple *origin;
    t_ray *r;
    t_intersection *xs;
    t_intersection *_hit;
    t_color *_color;

    ray_dir = sub_tuple(position, *space.view_point);
    norm(ray_dir);
    origin = tuplecpy(*space.view_point);
    r = ray(origin, ray_dir);
    xs = i_ray_sphere(sp, *r);
    _hit = hit(&xs);
    if (_hit)
    {
        _color = compute_shade(*_hit, r, sp, light);
        draw_pixel(&_canvas->img, cor.x, cor.y, _color);
        free(_color);
    }
    free_ray(&r);
    free_intersections(&xs);
}

void draw_sphere(const t_space space, t_canvas *_canvas, const t_sphere *sp)
{
    t_coordinates cor;
    t_tuple *position;
    double world_y;
    double world_x;

    cor.y = 0;
    while (cor.y < CANVAS_PIXELS - 1)
    {
        world_y = space.half - _canvas->pixel_size * cor.y;
        cor.x = 0;
        while (cor.x < CANVAS_PIXELS - 1)
        {
            world_x = -space.half + _canvas->pixel_size * cor.x;
            position = point(world_x, world_y, space.wall_z);
            compute_hit((const t_coordinates)cor, space, _canvas, sp, *(space.light), *position);
            free(position);
            cor.x++;
        }
        cor.y++;
    }
}