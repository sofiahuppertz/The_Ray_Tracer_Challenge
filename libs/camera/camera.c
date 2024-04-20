#include "camera.h"


static void fill_orientation(t_matrix *orientation, const t_tuple left, const t_tuple true_up, const t_tuple forward)
{
    orientation->m[0][0] = left.x;
    orientation->m[0][1] = left.y;
    orientation->m[0][2] = left.z;
    orientation->m[0][3] = 0.0;
    orientation->m[1][0] = true_up.x;
    orientation->m[1][1] = true_up.y;
    orientation->m[1][2] = true_up.z;
    orientation->m[1][3] = 0.0;
    orientation->m[2][0] = -forward.x;
    orientation->m[2][1] = -forward.y;
    orientation->m[2][2] = -forward.z;
    orientation->m[2][3] = 0.0;
    orientation->m[3][0] = 0.0;
    orientation->m[3][1] = 0.0;
    orientation->m[3][2] = 0.0;
    orientation->m[3][3] = 1.0;
}


t_matrix *view_transformation(t_tuple *from, t_tuple *to, t_tuple *up)
{
    t_tuple *forward;
    t_tuple *upn;
    t_tuple *left;
    t_tuple *true_up;
    t_matrix *m;

    if (!from || !to || !up || from->tf.type != POINT || to->tf.type != POINT || up->tf.type != VECTOR)
    {
        printf("Error: view_transformation: invalid arguments.\n");
        return identity(4);
    }
    forward = sub_tuple(*to, *from);
    norm(forward);
    upn = tuplecpy(*up);
    norm(upn);
    left = cross(*forward, *upn);
    norm(left);
    true_up = cross(*left, *forward);
    m = matrix(4, 4);
    fill_orientation(m, *left, *true_up, *forward);
    m = chain_transformations(translation(-from->x, -from->y, -from->z), m, NULL);
    free_tuples(from, to, up, forward, upn, left, true_up, NULL);
    return m;
}

t_camera *camera(unsigned int hsize, unsigned int vsize, double field_of_view)
{
    t_camera *cam;

    cam = (t_camera *)calloc(1, sizeof(t_camera));
    if (!cam)
    {
        printf("Error: camera: calloc failed.\n");
        return NULL;
    }
    cam->hsize = (double)hsize;
    cam->vsize = (double)vsize;
    cam->field_of_view = field_of_view;
    pixel_size(cam);
    cam->vt = identity(4);
    cam->tf.type = CAMERA;
    cam->tf.transform = NULL;
    return cam;
}


void pixel_size(t_camera *cam)
{
    double half_view;
    double aspect;

    half_view = tan(cam->field_of_view / 2);
    aspect = cam->hsize / cam->vsize;
    if (aspect >= 1)
    {
        cam->half_width = half_view;
        cam->half_height = half_view / aspect;
    }
    else
    {
        cam->half_width = half_view * aspect;
        cam->half_height = half_view;
    }
    cam->pixel_size = (cam->half_width * 2) / cam->hsize;
}

void free_camera(t_camera **cam)
{
    free_matrix(&(*cam)->vt);
    free(*cam);
    *cam = NULL;
}

t_ray *ray_for_pixel(t_camera *cam, double pixel_x, double pixel_y)
{
    t_ray *r;
    t_tuple *origin;
    t_tuple *direction;
    t_tuple *pixel;
    double world_cords[2];

    // Calculate the world coordinates of the pixel
    world_cords[0] = cam->half_width - (pixel_x + 0.5) * cam->pixel_size;
    world_cords[1] = cam->half_height - (pixel_y + 0.5) * cam->pixel_size;

    // Transform the pixel in world coordinates to camera coordinates
    pixel = point(world_cords[0], world_cords[1], -1);
    set_transform(POINT, (void*)pixel, inverse(*cam->vt));

    // Create the ray: origin is the camera, direction is the normed vector from the camera to the pixel
    origin = point(0, 0, 0);
    set_transform(POINT, (void*)origin, inverse(*cam->vt));
    direction = sub_tuple(*pixel, *origin);
    norm(direction);
    r = ray(origin, direction);
    free(pixel);

    return r;
}